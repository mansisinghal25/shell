#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/stat.h>
#include <fcntl.h>  
#include <stdlib.h>
#include <string.h>


void main(int rc, char **b) {

		if (strcmp(b[1],"-n")==0){

		int i=2;
		int count=1;
        while (b[i]!=NULL){
		FILE *file = fopen(b[i], "r");
        if (file == NULL) {
        printf("Error! opening file");
        exit(1);}
        char line[400];
        while(fgets(line, sizeof(line),file)){

        	printf("%d) %s\n",count,line);
        	count++;
        }
        i = i +1;
    	}
		}
		if (strcmp(b[1],"--number")==0){

		int i=2;
		int count=1;
        while (b[i]!=NULL){
		FILE *file = fopen(b[i], "r");
        if (file == NULL) {
        printf("Error! opening file");
        exit(1);}
        char line[400];
        while(fgets(line, sizeof(line),file)){

        	printf("%d) %s\n",count,line);
        	count++;
        }
        i = i +1;
    	}
		}
		else if (strcmp(b[1],"--help")==0){
				printf("Usage: cat [OPTION]... [FILE]...\n");
				printf("Concatenate FILE(s) to standard output.\n");
				printf("-n, --number             number all output line\n");
				printf("--help     display this help and exit\n");
				printf("Example: cat f  g  Output f's contents,  then g's contents.\n");
		}
		else {
			int i=1;
		
        while (b[i]!=NULL){
		FILE *file = fopen(b[i], "r");
        if (file == NULL) {
        printf("Error! opening file");
        exit(1);}
        char line[400];
        while(fgets(line, sizeof(line),file)){
        	printf(" %s\n",line);      	
        }
        i = i +1;
    	}
		}


}