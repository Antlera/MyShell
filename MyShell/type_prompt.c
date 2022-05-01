/* ************************************************************************
> File Name:     type_prompt.c
> Author:       Antlers
> Created Time:  Sun Apr 24 10:49:52 2022
> Description:   
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pwd.h>
#include "type_prompt.h"
void type_prompt(char *prompt){
    printf("> ");
    struct passwd *pwd;
    char hostname[MAX_NAME_LEN];
    char pathname[MAX_PATH_LEN];
    int length;
    pwd = getpwuid(getuid());
    getcwd(pathname,MAX_PATH_LEN);//获取现在的工作目录并存储于pathname
    if(gethostname(hostname,MAX_NAME_LEN)==0)
        sprintf(prompt,"[Ysh]%s@%s:",pwd->pw_name,hostname);
    else
        sprintf(prompt,"[Ysh]%s@unknown:",pwd->pw_name);
}
/* int main(){ */
/*     char *prompt = malloc(sizeof(char*)*max_prompt_len); */
/*     type_prompt(prompt); */
/*     printf("%s",prompt); */
/*     free(prompt); */
/*     return 0; */
/* } */

