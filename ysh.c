/* ************************************************************************
> File Name:     ysh.c
> Author:       Antlers
> Created Time:  Sat Apr 23 16:28:31 2022
> Description:   
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "read_command.h"
#include "type_prompt.h"
#include "builtin_command.h"
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
    pid_t chdPid;
    parameters = malloc(sizeof(char *) * (MAXARG + 2));
    buffer = malloc(sizeof(char*)*MAX_BUFFER_LEN);
    prompt = malloc(sizeof(char*)*MAX_PROMPT_LEN);
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
        if(builtin_command(command,parameters))
            continue;

        if ((chdPid = fork())!=0)
        {
            //parent code
            waitpid(chdPid, &status, 0);
        }
        else{
            //child code
            execvp(command, parameters);
        }

    } while (loopStatus);
    free(parameters);
    free(buffer);
}

