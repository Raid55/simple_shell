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

/*Main Functions Prototypes*/
void _shell_loop_init(char **);
void _shell_instance(char **);

/*Side Functions Prototypes*/
void exec_process(char *, char **);
char **tokeniser(char **, char *);

#endif
