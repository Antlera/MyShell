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
#include "MyShell.h"

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
    int loopStatus = 1;
    int status = 1;
    int paraNum;
    pid_t chdPid;
    parameters = malloc(sizeof(char *) * (MAXARG + 2));
    buffer = malloc(sizeof(char) * MAXLINE);
    if (parameters == NULL || buffer == NULL)
    {
        printf("Ysh error:malloc failed.\n");
        return;
    }
    do
    {
        type_prompt("> ");
        paraNum = read_command(&command,parameters,"> ");
        if (paraNum == -1)
        {
            continue;//用户未输入参数
        }
        paraNum--;
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

