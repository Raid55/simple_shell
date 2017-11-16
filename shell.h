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
#define _ERR_ 0 /*there was an error in the shell instance*/
#define _CLEAR_ 1 /*nothing is currently wrong with the curr instance*/
#define _SKIP_ 2 /*skip everything and loop the instance*/
#define _SHELL_END_ 3 /*skip everything, end shell and exit instance*/
#define _BUILT_IN_ 4 /*arg is a built in so execve is not run in instance*/
#define _PATH_NREADY_ 5 /*arg is not ready to be executed in instance*/
#define _PATH_READY_ 6 /*path is now ready to be executed in instance*/

/*Main Functions Prototypes*/
void _shell_loop_init();
int _shell_instance();

/*Bundled/Operative Prototypes*/
void exec_process(char *, char **);
char **tokeniser(char **, char *);
char *get_path_args(char*);

/*Direct/Mini Prototypes*/
char *_find_key_get_value(char **, char *);
char *_find_x_path(char **, char *);
unsigned int _is_arg_run_ready(char *arg);
char *_strclear(char **dest);
char *_stralloc(int, ...);

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

#endif
