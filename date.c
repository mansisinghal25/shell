#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <string.h>

void main(int rc, char **b) 
{ 
  
    struct tm* local; 
    time_t t = time(NULL); 
  
    // Get the localtime 
    if (b[1]==NULL){
    local = localtime(&t); 
  
    printf("%s\n",asctime(local)); }
    if (strcmp(b[1],"-u")==0){
    	local = gmtime(&t);
    	printf("%s\n",asctime(local));
    }
    if (strcmp(b[1],"--utc")==0){
    	local = gmtime(&t);
    	printf("%s\n",asctime(local));
    }
if (strcmp(b[1],"--universal")==0){
    	local = gmtime(&t);
    	printf("%s\n",asctime(local));
    }
    else if (strcmp(b[1],"--help")==0){
    	printf("Usage: date [OPTION]...\n");
    	printf("Display the current time in the given FORMAT, or set the system date.\n");
    	printf("-u, --utc, --universal     print or set Coordinated Universal Time (UTC)\n");
    	printf("--help     display this help and exit\n");
    }

} 