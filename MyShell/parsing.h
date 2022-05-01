/* ************************************************************************
> File Name:     parsing.h
> Author:       Antlers
> Created Time:  Thu Apr 28 17:59:19 2022
> Description:   
 ************************************************************************/
enum ParseFlag{
   INIT=0, BACKGROUND=1,IN_REDIRECT=2,OUT_REDIRECT=4,OUT_REDIRECT_APPEND=8,IS_PIPED=16
};
struct ParseInfo
{
    int flag;
    char *inFile;
    char *outFile;
    char* command2;
    char** parameters2;
};
int parse_info_init(struct ParseInfo *info);
int parsing(char **parameters, int paraNum,struct ParseInfo *info);

    

