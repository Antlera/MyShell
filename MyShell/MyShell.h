/* ************************************************************************
> File Name:     type_prompt.h
> Author:       Antlers
> Created Time:  Sun Apr 24 10:34:58 2022
> Description:   
 ************************************************************************/
#define MAXARG 20
#define MAX_PROMPT 1024
#define MAXLINE 4096 //the length of all args is ARG_MAX
char *buffer;
void type_prompt(char*);
int read_command(char **,char **, char*);

