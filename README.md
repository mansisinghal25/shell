# Shell
Designed a simple shell in C using system calls. The shell is capable of handling 10 commands equally split across internal &amp; external ones. 

The options and commands that MyOwnShell takes are described in detail below:

EXTERNAL COMMANDS:

1. mkdir <br />
Usage: mkdir [OPTION]... DIRECTORY… <br />
Any number of directories can be given as an input there is no limit on that. <br />
Options: -v, --help <br />
Errors handled: <br />
➔ If no directory name is provided then an error is thrown. <br />
➔ If directory couldn’t be created due to some reason then an error is thrown. <br />

2. cat <br />
Usage: cat [OPTION]... [FILE].. <br />
Any number of files can be given as an input there is no limit on that. <br />
Options: -n, --help
Errors handled:
➔ If the given file doesn’t open or doesn’t exist then an error will be thrown.

3. date
Usage: date [OPTION]...
Options: -u,--help
Assumptions: The default time will be according to the time in the system.

4. ls
Usage: ls [options][dir]
Options : -1, -a
Assumptions:
➔ If no directory is provided then the files of the current directory will be printed.
➔ The shell continues in the same line.

5. rm
Usage: rm [OPTION]... [FILE]...
Options: -v, --help
Any number of files can be given as an input there is no limit on that.
Errors handled:
➔ If the given file doesn’t exist then an error will be thrown.

INTERNAL COMMANDS:

1. exit
This command will simply exit the shell, no more inputs will be taken unless the shell
is started again.

2. cd
Usage: cd [option][dir]
Options:
--help, -L
Errors handled:
➔ if no arguments are passed with cd an error warning will be thrown.
➔ If chdir is not able to change directory then it return a non zero value and an
error will be thrown.
Assumptions: cd ~ is not a valid command.

3. Pwd
Usage: pwd [option]
Options:
--help, -P
Assumptions: No symbolic links will be printed. The physical address will be printed.

4. Echo
Usage: echo [OPTION][text]
Options: -E, --help
Assumptions: no echo “string” cases are considered. Echo will simply display the text
that has been provided.

5. history
Usage: history [options]
Options: -c, --help
Errors handled:
➔ If the history file doesn’t open then an error will be thrown.
Assumptions: The entire history is cleared with -c option.

# Working Examples
<img width="896" alt="Screenshot 2021-06-13 at 1 38 48 AM" src="https://user-images.githubusercontent.com/55681967/121788127-5a229880-cbe8-11eb-9d96-b3da0fa26a50.png">
<img width="802" alt="Screenshot 2021-06-13 at 1 39 06 AM" src="https://user-images.githubusercontent.com/55681967/121788142-80483880-cbe8-11eb-9797-e12fc4169a6b.png">
<img width="894" alt="Screenshot 2021-06-13 at 1 39 21 AM" src="https://user-images.githubusercontent.com/55681967/121788145-89390a00-cbe8-11eb-88b8-8f6be4136630.png">
