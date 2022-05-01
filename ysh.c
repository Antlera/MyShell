/* ************************************************************************
> File Name:     ysh.c
> Author:       Antlers
> Created Time:  Sat Apr 23 16:28:31 2022
> Description:   
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <readline/history.h>
#include "read_command.h"
#include "type_prompt.h"
#include "parsing.h"
#include "builtin_command.h"
HISTORY_STATE *histState;
HIST_ENTRY **histList;
void ysh_loop(void);
int main(int argc,char **argv){
    // Load config files, if any
    
    // Run command loop.
    ysh_loop();
    //Perform any shutdown/cleanup
    return EXIT_SUCCESS;
}
void ysh_loop(void){
    char *line;
    char *command = NULL;
    char **parameters;
    char* buffer;
    char* prompt;
    int loopStatus = 1;
    int status = 1;
    int paraNum;  
    struct ParseInfo info;
    int pipefd[2];
    int infd,outfd;
    pid_t chdPid,chdPid2;
    parameters = malloc(sizeof(char *) * (MAXARG + 2));
    buffer = malloc(sizeof(char*)*MAX_BUFFER_LEN);
    prompt = malloc(sizeof(char*)*MAX_PROMPT_LEN);
    using_history();//初始化命令历史
    if (parameters == NULL || buffer == NULL)
    {
        printf("Ysh error:malloc failed.\n");
        return;
    }
    do
    {
        type_prompt(prompt);
        paraNum = read_command(&command,parameters,prompt,buffer);
        if (paraNum == -1)
        {
            continue;//用户未输入参数
        }
        paraNum--;
        
        for(int i =0;i<paraNum;i++)
        {
            printf("%s\n",parameters[i]);
        }
        printf("flag: %d\n",info.flag);
        parsing(parameters,paraNum,&info);
        for(int i =0;i<paraNum;i++)
        {
            if(parameters[i]!=NULL)
                printf("%s\n",parameters[i]);
        }
        printf("flag: %d\n",info.flag);
        if(builtin_command(command,parameters))
            continue;
        if(info.flag & IS_PIPED)
        {
            if(pipe(pipefd)<0)
            {
                printf("Ysh error: pipe failed.\n");
                exit(0);
            }
        }
        if ((chdPid = fork())!=0)
        {
            if(info.flag & IS_PIPED)
            {
               if((chdPid2=fork())!=0) 
               {
                   //parent code
                   close(pipefd[0]);
                   close(pipefd[1]);
                   waitpid(chdPid2,&status,0);
               }
               else
               {
                   printf("command2:%s\n",info.command2);
                   close(pipefd[1]);
                   close(fileno(stdin));
                   dup2(pipefd[0],fileno(stdin));
                   close(pipefd[0]);
                   execvp(info.command2,info.parameters2);
               }
            }
            if  (info.flag & BACKGROUND)
            {
                printf("process is runing background!\n");
            }
            else
            {
                //parent code
                waitpid(chdPid, &status, 0);
            }
        }
        else{
            if(info.flag & IS_PIPED)
            {
                if(!(info.flag & OUT_REDIRECT)&&!(info.flag & OUT_REDIRECT_APPEND))
                {
                    printf("only piped\n");
                    close(pipefd[0]);//关闭读端
                    close(fileno(stdout));//关闭标准输出，并重用为指定写端
                    dup2(pipefd[1],fileno(stdout));
                    close(pipefd[1]);
                }

                else
                {
                    close(pipefd[0]);
                    close(pipefd[1]);//send a EOF to command2
                    if(info.flag & OUT_REDIRECT)
                    {
                        printf("piped and OUT_REDIRECT\n");
                        outfd = open(info.outFile, O_WRONLY|O_CREAT|O_TRUNC,0666);
                    }
                    else
                    {
                        printf("piped and OUT_REDIRECT_APPEND\n");
                        outfd = open(info.outFile, O_WRONLY|O_APPEND,0666);
                    }
                    close(fileno(stdout));
                    dup2(outfd,fileno(stdout));
                    close(outfd);
                }
            }
            else
            {
                if(info.flag & OUT_REDIRECT) 
                {
                    printf("not piped and OUT_REDIRECT\n");
                    outfd = open(info.outFile, O_WRONLY|O_CREAT|O_TRUNC,0666);
                    close(fileno(stdout));
                    dup2(outfd,fileno(stdout));
                    close(outfd);
                }
                else if(info.flag & OUT_REDIRECT_APPEND)
                {
                    printf("not piped and OUT_REDIRECT_APPEND\n");
                    outfd = open(info.outFile, O_WRONLY|O_APPEND,0666);
                    close(fileno(stdout));
                    dup2(outfd,fileno(stdout));
                    close(outfd);
                }
            }
            if(info.flag & IN_REDIRECT)
            {
                printf("IN_REDIRECT\n");
                infd = open(info.inFile, O_CREAT|O_RDONLY,0666);
                close(fileno(stdin));
                dup2(infd,fileno(stdin));
                close(infd);
            }
            //child code
            execvp(command, parameters);
        }

    } while (loopStatus);
    free(parameters);
    free(buffer); 
    free(histState);
    free(histList);
}

