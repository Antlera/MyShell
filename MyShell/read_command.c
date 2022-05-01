/* ************************************************************************
> File Name:     readcommand.c
> Author:       Antlers
> Created Time:  Sun Apr 24 12:28:24 2022
> Description:   
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "read_command.h"
int read_command(char **command,char **parameters,char *prompt,char *buffer){
    buffer = readline(prompt);
    if(feof(stdin))
    {
        printf("\n");
        exit(0);
    }
    add_history(buffer);
    if(buffer[0] == '\0')
        return -1;
    char *pStart,*pEnd;
    int count = 0;
    int isFinished = 0;
    pStart = pEnd = buffer;
    while(!isFinished){
        //过滤前面多余的空格和tab
        while((*pEnd == ' ' && *pStart == ' ')||(*pEnd== '\t'&&*pStart== '\t')){
            pStart++;
            pEnd++;
        }
        //过滤后若直接为空，或者换行符，则结束read_command
        if(*pEnd == '\0'|| *pEnd == '\n'){
            if(count == 0){
                return -1;
            }
            break;
        }
        // 将pEnd调整至第一个分隔符处
        while(*pEnd != ' ' && *pEnd != '\0' && *pEnd != '\n')
            pEnd++;
        if (count == 0)
        {
            char *p = pEnd;//定位命令的末尾
            *command = pStart;//命令从最开始的非空格开始
            while (p!=pStart && *p != '/')
            {
                p--;//定位至参数[0]和command的分界，即"/"
            }
            if(*p == '/'){
                p++; //将参数test与./test命令分离
            }
            parameters[0] = p;
            count += 2;//定位count多1的位置
        }
        else if(count <= MAXARG)
        {
            parameters[count - 1] = pStart;
            count++;
        }
        else
        {
            break;
        }

        if (*pEnd == '\0' || *pEnd == '\n')
        {
            *pEnd = '\0';
            isFinished = 1;
        }
        else{
            *pEnd = '\0';//为参数命令做隔断
            pEnd++;//移动指针，为下一次搜索做准备
            pStart = pEnd;
        }
    }
    parameters[count - 1] = NULL;//将参数表最后一个设为NULL(0)
    return count;
}
