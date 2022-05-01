/* ************************************************************************
> File Name:     parsing.c
> Author:       Antlers
> Created Time:  Thu Apr 28 17:58:42 2022
> Description:   
 ************************************************************************/
#include<string.h>
#include<stdlib.h>
#include"parsing.h"
int parse_info_init(struct ParseInfo *info){
    info->flag=INIT;
    info->inFile =NULL;
    info->outFile=NULL;
    info->command2=NULL;
    info->parameters2=NULL;
    return 0;
}

int parsing(char **parameters, int paraNum,struct ParseInfo *info)
{
    parse_info_init(info);
    if(strcmp(parameters[paraNum-1] ,"&") == 0)
    {
        /* 检查末尾是否有后台任务命令标识符 */
        info->flag |= BACKGROUND;//相关标志位置位
        parameters[paraNum-1]=NULL;//去除相应符号
        paraNum--;
    }
    for(int i = 0;i<paraNum;)
    {
        if(strcmp(parameters[i],"<<")==0 || strcmp(parameters[i],"<")==0)    
        {
            info->flag |= IN_REDIRECT;
            info->inFile = parameters[i+1];
            parameters[i]=NULL;
            i+=2;
        }
        else if(strcmp(parameters[i],">")==0)
        {
            info->flag |= OUT_REDIRECT;
            info->outFile = parameters[i+1];
            parameters[i]=NULL;
            i+=2;
        }
        else if(strcmp(parameters[i],">>")==0)
        {
            info->flag |= OUT_REDIRECT_APPEND;
            info->outFile = parameters[i+1];
            parameters[i]=NULL;
            i+=2;
        }
        else if(strcmp(parameters[i],"|")==0)
        {
            char *p;
            info->flag |= IS_PIPED;
            parameters[i]=NULL;
            info->command2 = parameters[i+1];
            info->parameters2 = &parameters[i+1];
            p = info->parameters2[0]+strlen(info->parameters2[0]);
            while(p!=info->parameters2[0]&&*p!='/')
                p--;//调整指针至/或命令头部
            if(*p == '/')
                p++;
            info->parameters2[0]=p;
            i += 2;
        }
        else
            i++;
        

    }
}
/* int main(){ */
/*     struct ParseInfo *info = malloc(sizeof(ParseInfo)); */
/*     char **para = malloc(10*sizeof(char*)); */
/*     for(int i = 0;i<10;i++) */
/*     { */
/*         para[i] = malloc(255*sizeof(char)); */
/*     } */
/*     strcpy(para[]) */
/* } */
