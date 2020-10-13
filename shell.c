#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


int cd(char **args);
int exit_call(char **args);
int pwd(char **args);
int echo(char **args);
int history(char **args);
char *builtin_str[] = { "cd","exit", "pwd" , "echo", "history"};

int (*builtin_func[]) (char **) = { &cd, &exit_call, &pwd, &echo, &history};

int exit_call(char **args){
  return 0;
}

int cd(char **args){
  if (args[1] == NULL) {
    fprintf(stderr, "error: expected argument to \"cd\"\n");
  } 
  else if (strcmp(args[1],"-L")!=0 &&strcmp(args[1],"--help")!=0) {
    if (chdir(args[1]) != 0) {
      perror("chdir error");
    }

  }
  else if (strcmp(args[1],"-L")==0 ){
  	if (chdir(args[2]) != 0) {
      perror("chdir error");
    }
  }
  else if (strcmp(args[1],"--help")==0){
    	printf("Usage:  cd [-L][dir] \n");
        printf("Change the shell working directory.\n");
        printf("CChange the current directory to DIR.  The default DIR is the value of the HOME shell variable.\n");
        printf(" Options: -L	force symbolic links to be followed: resolve symbolic links in DIR after processing instances of `..'\n");
        printf("`..' is processed by removing the immediately previous pathname component back to a slash or the beginning of DIR..");
    }


  return 1;
}

int pwd(char **args){
	if (args[1]== NULL){
	char name[2000]; 
    getcwd(name, sizeof(name)); 
    printf("%s\n", name);}

    else if (strcmp(args[1],"-P")==0){
	char name[2000]; 
    getcwd(name, sizeof(name)); 
    printf("%s\n", name);
    }
    else if (strcmp(args[1],"--help")==0){
    	printf("Usage:  pwd [-P] \n");
        printf("Print the name of the current working directory.\n");
        printf(" Options: -P	print the physical directory, without any symbolic links\n");
        printf("By default, `pwd' behaves as if `-P' were specified.");
    }

	return 1;
}

int echo(char **args){
	if (strcmp(args[1],"-E")!=0 &&strcmp(args[1],"--help")!=0 ){
	int i=1;
	while (args[i]!=NULL){
		printf("%s ", args[i]);
		i = i+1;
	}}
	else if (strcmp(args[1],"-E")==0){
	int i=2;
	while (args[i]!=NULL){
		printf("%s ", args[i]);
		i = i+1;
	}}

	else if (strcmp(args[1],"--help")==0){
		printf("Usage: echo [SHORT-OPTION].. \n");
        printf("display a line of text.\n");
        printf("Options:\n");
        printf(" -E     disable interpretation of backslash escapes\n");
        printf("--help display this help and exit");
	}

	return 1;
}
int history(char **args){

	
	if (args[1]==NULL){
	FILE *file = fopen("/home/mansisinghal/Desktop/OS1_2019370/Answer2/history.txt", "r");
    if (file == NULL) {
        printf("Error! opening file");
        fclose(file);
        exit(1);}
        int count =1;
        //printf("yahan tak\n");
        char line[2000];
        while(fgets(line, sizeof(line),file)){
        	printf("%d) %s\n",count,line);
        	count++;
        }
        fclose(file);
    }
    else if (strcmp(args[1],"--help")==0){
		printf("Usage: history [-c]  \n");
        printf("Display or manipulate the history list.\n");
        printf("Display the history list with line numbers\n");
        printf("Options:\n");
        printf("-c	clear the history list by deleting all of the entries\n");
        printf("--help     display this help and exit\n");
        printf("history is the name of the history file.\n");
	}

	else if (strcmp(args[1],"-c")==0){
		remove("/home/mansisinghal/Desktop/OS1_2019370/Answer2/history.txt");
	}
	return 1;
}
char *read_line()
{
  char *line = NULL;
  ssize_t bufsize = 0; 
  if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  // We recieved an EOF
    } else  {
      perror("readline");
      exit(EXIT_FAILURE);
    }
  }
  //char cline[];
 // strcopy(cline,line);
  //strcopy()
  //fputs(cline,history);
  //fputs("\n", history);
	FILE *file_o = fopen("/home/mansisinghal/Desktop/OS1_2019370/Answer2/history.txt", "a+");
	   if ( file_o == NULL ) 
    { 
        printf( "history file failed to open." ) ; 
    } 
    else{
    	fputs(line, file_o) ;    
    }
    fclose(file_o);

  return line;
}
int size_help() {
  return sizeof(builtin_str) / sizeof(char *);
}
void internal(char **args){
	//internal commands
	 for (int i = 0; i < size_help(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      (*builtin_func[i])(args);
    }
  }
	
}
char **separator(char *line)
{
  int position = 0;
  char **tokens = malloc(80 * sizeof(char*));
  char *token;

  token = strtok(line, " \t\n");
  //int hh = helper_fun;
  while (token != NULL) {
    tokens[position] = token;
    position++;
    token = strtok(NULL, " \t\n");
  }
  tokens[position] = NULL;
  return tokens;
}




int execute(char **args){
  
  if (args[0] == NULL) {
    return 1;
  }
  //int hh = helper_fun;
 internal(args);
  if (strcmp(args[0],"ls")==0){
  	pid_t pid, wpid;
   int status;

  pid = fork();
    if (pid == 0) {
    	args[0] = "/home/mansisinghal/Desktop/OS1_2019370/Answer2/ls";
    if (execv("/home/mansisinghal/Desktop/OS1_2019370/Answer2/ls", args) == -1) {
      perror("child forking error");
    }
    exit(EXIT_FAILURE);
  }
   else if (pid ==-1) {
    // Error forking
    perror("forking error");
  } else {
     waitpid(pid, &status, WUNTRACED);
      //waitpid(pid, &status, WUNTRACED);
   
  }
  }
  else if (strcmp(args[0],"mkdir")==0){
pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
  	args[0] = "/home/mansisinghal/Desktop/OS1_2019370/Answer2/mkdir";
    if (execv("/home/mansisinghal/Desktop/OS1_2019370/Answer2/mkdir", args) == -1) {
      perror("child forking error");
    }
    exit(EXIT_FAILURE);
  }
   else if (pid ==-1) {
    // Error forking
    perror("forking error");
  } else {
   waitpid(pid, &status, WUNTRACED);
      //waitpid(pid, &status, WUNTRACED);
   
  }
  }
   else if (strcmp(args[0],"cat")==0){
  	pid_t pid, wpid;
   int status;

  pid = fork();
    if (pid == 0) {
    	args[0] = "/home/mansisinghal/Desktop/OS1_2019370/Answer2/cat";
    if (execv("/home/mansisinghal/Desktop/OS1_2019370/Answer2/cat", args) == -1) {
      perror("child forking error");
    }
    exit(EXIT_FAILURE);
  }
   else if (pid ==-1) {
    // Error forking
    perror("forking error");
  } else {
    waitpid(pid, &status, WUNTRACED);

  }
  }
   else if (strcmp(args[0],"rm")==0){
  	pid_t pid, wpid;
   int status;

  pid = fork();
    if (pid == 0) {
    	args[0] = "/home/mansisinghal/Desktop/OS1_2019370/Answer2/rm";
    if (execv("/home/mansisinghal/Desktop/OS1_2019370/Answer2/rm", args) == -1) {
      perror("forking error");
    }
    exit(EXIT_FAILURE);
  }
   else if (pid== -1) {
    // Error forking
    perror("forking error");
  } else {
    // Parent process
    waitpid(pid, &status, WUNTRACED);
 
  }}
   else if (strcmp(args[0],"date")==0){
  	pid_t pid, wpid;
   int status;

  pid = fork();
    if (pid == 0) {
    	args[0] = "/home/mansisinghal/Desktop/OS1_2019370/Answer2/date";
    if (execv("/home/mansisinghal/Desktop/OS1_2019370/Answer2/date", args) == -1) {
      perror("lsh this");
    }
    exit(EXIT_FAILURE);
  }
   else if (pid ==-1) {
    // Error forking
    perror("forking error");
  } else {
    // Parent process
    waitpid(pid, &status, WUNTRACED);
  
  }

  return 1;
}
}


void shell_start(void){
  char *line;
  char **args;
  int status;

  while (status) {
    printf("%s","MyOwnShell>");
    line = read_line();
    args = separator(line);
      if (strcmp(args[0],"exit")==0){
    	break;
    }
    status = execute(args);

  } 
}


int main(int argc, char **argv)
{
 
	
	//FILE *history
	//fptr = fopen("history.txt", "w");
  shell_start();

  return EXIT_SUCCESS;
}