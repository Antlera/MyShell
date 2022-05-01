/* ************************************************************************
> File Name:     builtin_command.c
> Author:       Antlers
> Created Time:  Tue Apr 26 21:18:56 2022
> Description:   
 ************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<pwd.h>
#include<readline/history.h>
#include"builtin_command.h"

int builtin_command(char *command, char **parameters)
{
    if(strcmp(command,"exit")==0||strcmp(command,"quit")==0)
    {
        exit(0);
    }
    else if(strcmp(command,"arthor")==0)
    {
        printf("This is a shell of Antlers!");
        return 1;
    }
    else if(strcmp(command,"cd")==0)
    {
        
        struct passwd *pwd; 
        pwd = getpwuid(getuid());
        char *cd_path = malloc(255*sizeof(char));
        char *last_cd_path = malloc(255*sizeof(char));
        strcpy(last_cd_path,pwd->pw_dir);
        if(parameters[1]==NULL)
        {
            // 仅有cd指令的情况下则转到用户主目录
            strcpy(cd_path,pwd->pw_dir);
        }
        else if(parameters[1][0]=='~')
        {
            // 以"~"开头将"~"补全为用户主目录
            strcpy(cd_path,pwd->pw_dir);
            strcpy(cd_path+strlen(pwd->pw_dir),parameters[1]+1);
        }
        else if(parameters[1][0]=='-')
        {
            // 返回上一次目录的功能
            strcpy(cd_path,last_cd_path);
        }
        else
        {
            //普通的cd命令，即cd path
            strcpy(cd_path,parameters[1]);
        }
        if(chdir(cd_path)!=0)
        {
            printf("> Ysh: cd: %s:%s\n",cd_path,strerror(errno));
            strcpy(last_cd_path,cd_path);
            free(cd_path);
        }
        return 1;
    }
    else if(strcmp(command,"history")==0)
    {
        
        extern HISTORY_STATE *histState;
        extern HIST_ENTRY **histList;
        /* 获取history list的状态（offset，length，size) */
        histState = history_get_history_state();
        /* 获取历史列表 */
        histList = history_list();
        if(parameters[1]==NULL)
        {
            for(int i = 0;i <histState->length;i++)
            {
                printf("%d %8s\n",i+1,histList[i]->line);
                /* free(histList[i]); */
            }
        }
        return 1;

    }
    
    return 0;
}
/* int main() */
/* { */
    
/*     /1* struct passwd *pwd; *1/ */
/*     /1* pwd = getpwuid(getuid()); *1/ */
/*     /1* printf("%s",pwd->pw_dir); *1/ */
/*     /1* if(chdir(pwd->pw_dir)!=0) *1/ */
/*     /1* { *1/ */
/*     /1*     printf("> Ysh: cd: %s:%s\n",pwd->pw_dir,strerror(errno)); *1/ */
/*     /1*     /2* free(cd_path); *2/ *1/ */
/*     /1* } *1/ */
/*     char path[255]; */
/*     getcwd(path,255); */
/*     printf("%s\n",path); */
/*     char *command = "cd"; */
/*     char **parameters = malloc(10*sizeof(char*)); */
/*     parameters[0]=malloc(5*sizeof(char)); */
/*     parameters[0]=command; */
/*     parameters[1]=malloc(25*sizeof(char)); */
/*     /1* parameters[1]="~/2019141480012/bin/"; *1/ */
/*     scanf("%s",parameters[1]); */
/*     builtin_command(command,parameters); */

/*     getcwd(path,255); */
/*     printf("%s\n",path); */
/* } */
