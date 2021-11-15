#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>


// only 1 space between each argument, no more than 5 arguments, already formatted
char ** parse_args(char * line){
    char ** args = calloc(5, sizeof(char *));
    args[0] = strsep(&line, " ");
    int i = 1;
    for(i = 1; i < 5; i++){
        args[i] = strsep(&line, " ");
        //strsep returns NULL if no more tokens are found, exit if such
        if(args[i] == NULL) break;
    } 
    return args;
}   

int main(int argc, char*argv[]){
    char test[100] = "ls";
    char test2[100] = "ls -a -l";
    char ** args = parse_args(test2);
    execvp(args[0], args);
    return 0;
}