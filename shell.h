#ifndef _SHELL_H_
#define _SHELL_H_

/*Standard Libs*/
#include <stdio.h> /*for testing*/
#include <stdlib.h> /*malloc, free, etc...*/
#include <sys/wait.h> /*wait()*/
#include <unistd.h> /*system libraries*/
#include <string.h> /*string manip function*/
#include <sys/types.h> /*datatypes for syscall returns*/
#include <sys/stat.h> /*I need a detective to investigate this...STAT*/
#include <fcntl.h> /*fork system */
#include <stdarg.h> /*varidiadenenticalistic functions...you know what i mean*/

/*System environment*/
extern char **environ;

/*SHELL INSTANCE STAGES*/
#define _ERR_         0 /*there was an error in the shell instance*/
#define _NORMAL_       1 /*nothing is currently wrong with the curr instance*/
#define _SKIP_        2 /*skip everything and loop the instance*/
#define _SHELL_END_   3 /*skip everything, end shell and exit instance*/
#define _BUILT_IN_    4 /*arg is a built in so execve is not run in instance*/
#define _PATH_NREADY_ 5 /*arg is not ready to be executed in instance*/
#define _PATH_READY_  6 /*path is now ready to be executed in instance*/

/*Main Functions Prototypes*/
void _shell_loop_init(); /*init shell loop function and error handling*/
int _shell_instance(); /*an instance of the shell, along with all its vars*/

/*Bundled/Operative Prototypes*/
void exec_process(char *, char **); /*executes process in child*/
char **tokeniser(char **, char *); /*tokenises the world*/
char *get_path_args(char*); /*bundled to get exec path in a string*/
char *generate_prompt_line(char *);

/*Direct/Mini Prototypes*/
char *_find_env_get_value(char *); /*finds key value in env var*/
char *_find_x_path(char **, char *); /*finds correct exec path for program*/
unsigned int _is_arg_run_ready(char *arg); /*is argument executable as is*/
char *_stralloc(int, ...); /*strallocates space for string in variadic styles*/
int _tokount(char *str, char *delimi); /*counts tokens in str*/

/*BUILT-IN FUNCTION AND STRUCT*/
int run_built_in(char **);
/*functions*/
int _bin_exit(char **);
int _bin_cd(char **);
int _bin_env(char **);
/*struct*/
typedef struct built_ins {
	char *command;
	int (*func)(char **);
} b_ins;
/*END OF BUILT-IN STUFF*/

/*COLOR CODES*/
#define _COLOR_RED_       "\x1b[31m"
#define _COLOR_GREEN_     "\x1b[32m"
#define _COLOR_YELLOW_    "\x1b[33m"
#define _COLOR_BLUE_      "\x1b[34m"
#define _COLOR_MAGENTA_   "\x1b[35m"
#define _COLOR_CYAN_      "\x1b[36m"
#define _BOLD_            "\e[1m"
#define _CLEAR_     "\x1b[0m"

#endif
