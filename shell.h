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

/*BUFF SIZE*/
#define _SHIA_LA_BEAUF_ 1024

/*SHELL INSTANCE STAGES*/
#define _ERR_         0 /*there was an error in the shell instance*/
#define _NORMAL_      1 /*nothing is currently wrong with the curr instance*/
#define _SKIP_        2 /*skip everything and loop the instance*/
#define _SHELL_END_   3 /*skip everything, end shell and exit instance*/
#define _BUILT_IN_    4 /*arg is a built in so execve is not run in instance*/
#define _PATH_NREADY_ 5 /*arg is not ready to be executed in instance*/
#define _PATH_READY_  6 /*path is now ready to be executed in instance*/

/*Main Functions Prototypes*/
/**
* _shell_instance - and instance of the shell
* Return: status code
*/
int _shell_instance(void); /* an instance of the shell */

/*Bundled/Operative Prototypes*/
/**
* exec_process - run program with arguments
* @program: program string
* @e_args: program arguments
* Returns: void
*/
void exec_process(char *program, char **e_args); /*executes process in child*/
/**
* tokeniser - tokenizes a string
* @buff: string to tokenize
* @pattern: delimiter string
* Return: array of tokens
*/
char **tokeniser(char **buff, char *pattern); /*tokenises the world*/
/**
* get_path_args - get absolute path for program name
* @program: program token
* Return: absolute path
*/
char *get_path_args(char *program); /*bundled to get exec path in a string*/
/**
* generate_prompt_line - display prompt
* @custom: custom prompt
* Return: prompt string in color
*/
char *generate_prompt_line(char *custom);
/*Direct/Mini Prototypes*/

/**
* _find_env_get_value - get value of key
* @key: key is key
* Return: pointer to first letter env value
*/
char *_find_env_get_value(char *key); /*finds key value in env var*/
/**
* _find_x_path - find path of program
* @env_paths: path token array
* @program: program string
* Return: absolute path of program
*/
char *_find_x_path(char **env_paths, char *program);
/*finds correct exec path for program*/
/**
* _is_arg_run_ready - tests for file access
* @arg: path to check
* Return: 1 on success, 0 on failure
*/
unsigned int _is_arg_run_ready(char *arg); /*is argument executable as is*/
/**
* _stralloc - concatenate count strings
* @count: string count
* Return: concatenated strings
*/
char *_stralloc(int count, ...);
/*strallocates space for string in variadic styles*/
/**
* _tokount - counts number of tokens
* @str: input string
* @delim: delimiter string
* Return: delimiter count
*/
int _tokount(char *str, char *delim); /*counts tokens in str*/

/*BUILT-IN FUNCTION AND STRUCT*/
/**
* run_built_in - run built-in function if found
* @args: argument array
* Return: shell instance status code
*/
int run_built_in(char **args);
/*functions*/
int _bin_exit(char **);
int _bin_cd(char **);
int _bin_env(char **);
/*struct*/
/**
* struct built_ins - command name and function to handle built-ins
* @command: command name
* @func: pointer to function
*
*/
typedef struct built_ins
{
	char *command;
	int (*func)(char **);
} b_ins;
/*END OF BUILT-IN STUFF*/

/*COLOR CODES*/
<<<<<<< HEAD
#define _COLOR_RED_       "\e[31m"
#define _COLOR_GREEN_     "\e[32m"
#define _COLOR_YELLOW_    "\e[33m"
#define _COLOR_BLUE_      "\e[34m"
#define _COLOR_MAGENTA_   "\e[35m"
#define _COLOR_CYAN_      "\e[36m"
#define _BOLD_            "\e[1m"
#define _CLEAR_	          "\e[0m"
=======
#define _COLOR_RED_       "\x1B[31m"
#define _COLOR_GREEN_     "\x1B[32m"
#define _COLOR_YELLOW_    "\x1B[33m"
#define _COLOR_BLUE_      "\x1B[34m"
#define _COLOR_MAGENTA_   "\x1B[35m"
#define _COLOR_CYAN_      "\x1B[36m"
#define _BOLD_            "\x1B[1m"
#define _CLEAR_     	  "\x1B[0m"

>>>>>>> 39a0c48da56c3203f267ed25dc8af62477f98a55
#endif
