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

/*SHELL INSTANCE STAGES*/
#define _CLEAR_ 0
#define _SKIP_ 1
#define _SHELL_END_ 2 
#define _BUILT_IN_ 3
#define _PATH_NREADY_ 4
#define _PATH_READY_ 5

/*Main Functions Prototypes*/
void _shell_loop_init(char **);
void _shell_instance(char **);

/*Side Functions Prototypes*/
void exec_process(char *, char **);
char **tokeniser(char **, char *);
char *get_path_args(char **, char*);

/*mini functions*/
char *_find_key_get_value(char **, char *);
char *_find_x_path(char **, char *);
unsigned int _is_arg_run_ready(char *arg);
/*BUILT-IN FUNCTION AND STRUCT*/
/*functions*/

/*struct*/
typedef struct built_ins {
	char *command;
	
} b_ins;
/*END OF BUILT-IN STUFF*/

#endif
