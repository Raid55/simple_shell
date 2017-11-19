#include "shell.h"
/**
 *
 *
 *
 *
 *
 *
 */
char **tokeniser(char **buff, char *pattern)
{
	int i;
    char *tok;
	char **_argv;
	char **tmp;
	int cTok;
	
	cTok = _tokount(*buff, pattern);
	
	tok = strtok(*buff, pattern);
    if (tok == NULL)
    	perror("no command passed: "), exit(0);
	
	_argv = malloc(sizeof(char *) * (cTok + 1));
    if (_argv == NULL)
        perror("Error in Allocation: "), exit(2);
    
	i = 1, _argv[0] = tok;
    while (tok != NULL)
    {
        tok = strtok(NULL, pattern);
        if (tok != NULL)
			_argv[i] = tok, i++;
    }

    _argv[i] = NULL;
    return(_argv);
}
/**
 *
 *
 */
void exec_process(char *program, char **e_args)
{
    pid_t cPid;

    cPid = fork();
    if (cPid == -1)
    	perror("twas the night before xmas and fork faild"), exit(EXIT_FAILURE);
    /*if child process*/
    if (cPid == 0)
    	if (execve(program, e_args, NULL) == -1)
        	perror("Error in running program:"), exit(EXIT_FAILURE);
}
/**
 *
 *
 */
