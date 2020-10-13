
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
  //int arg,char **args
void main(int rc, char **b) 
{ 
  
    if (strcmp(b[1],"-v")==0){
        if (b[2]==NULL){
            printf("Error: No directory name provided\n"); 
            exit(1); 
        }
        else {
            int i=2;
            while (b[i]!=NULL){
            char* name = b[i]; 
            int check = mkdir(name,0777);
            if (!check) {printf("created Directory %s\n",name);}; 
            i = i+1;}
        }
    }
    else if (strcmp(b[1],"--verbose")==0){
        if (b[2]==NULL){
            printf("Error: No directory name provided\n"); 
            exit(1); 
        }
        else {
            int i=2;
            while (b[i]!=NULL){
            char* name = b[i]; 
            int check = mkdir(name,0777);
           if (!check) {printf("created Directory %s\n",name);}
            i = i+1;}
            }
        }
        
    else if (strcmp(b[1],"--help")==0){
        printf("Usage: mkdir [OPTION]... DIRECTORY...\n");
        printf("Create the DIRECTORY(ies), if they do not already exist.\n");
        printf("Mandatory arguments to long options are mandatory for short options too.\n");
        printf("-v, --verbose   print a message for each created directory\n");
        printf("--help     display this help and exit\n");
    }
    else {
            int i=1;
            while (b[i]!=NULL){
            char* name = b[i]; 
            if (mkdir(name,0777)==-1){
            printf("Error: Unable to create directory\n"); 
            exit(1); 
    }
            i = i+1;}

    }
  
    system("dir"); 
} 