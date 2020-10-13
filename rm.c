#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h> 
#include <string.h>



void main(int rc, char **b){
	if (strcmp(b[1],"-v")==0){
		int i=2;
        while (b[i]!=NULL){
	
		if(unlink(b[i])==0){
		printf("removed:%s\n",b[i]);}
		else {
		printf("error:The file %s doesn't exist\n",b[i]);
		}
	i=i+1;
	}
}
	if (strcmp(b[1],"--verbose")==0){
		int i=2;
        while (b[i]!=NULL){
	
		if(unlink(b[i])==0){
		printf("removed:%s\n",b[i]);}
		else {
		printf("error:The file %s doesn't exist\n",b[i]);
		}
	i=i+1;
	}
}
	else if (strcmp(b[1],"--help")==0){
		printf("Usage: rm [OPTION]... [FILE]...\n");
		printf("Remove (unlink) the FILE(s).\n");
 		printf("-v, --verbose         explain what is being done\n");
 		printf("--help     display this help and exit\n");
 		printf("By default, rm does not remove directories.\n");

	}
	else{
		int i=1;
        while (b[i]!=NULL){
		
		if(unlink(b[i])!=0){
		printf("error:The file %s doesn't exist\n",b[i]);
	}
	i=i+1;
	}
	}
}
