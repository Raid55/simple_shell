#include "shell.h"
/**
 *
 *
 *
 *
 *
 *
 */
int _tokount(char *str, char *delim)
{
	int i = 0, j = 0;
	int c = 0;

	while (delim[i])
	{
		while (str[j])
			if (str[j++] == delim[i] && str[j] != delim[i])
				c++; /*haha c ++, get it...what a joke*/
		j = 0;
		i++;
	}
	return (c);
}
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
char *_find_x_path(char **env_paths, char *program)
{
	int i = 1;
	int pCount = strlen(program);
	int pathCount;
	char *tmp;
	
	tmp = _stralloc(3, env_paths[0], "/", program);
	while (access(tmp, X_OK) == -1 && env_paths[i] != NULL)
	{
		free (tmp);
		tmp = _stralloc(3, env_paths[i], "/", program);
		/* printf("[inloop: %s]\n", tmp); */
		i++;
	}
	if (env_paths[i] == NULL)
		return (NULL);
	else
		return (tmp);
}
char *_stralloc(int count, ...)
{
	va_list valist;
	char *tmp_arg;
	char *tmp_ptr;
	char *tmp_ret;
	int sLen;
	int aLen;

	va_start(valist, count);
	
	tmp_arg = va_arg(valist, char *), count--;	
	aLen = strlen(tmp_arg);

	tmp_ret = malloc(sizeof(char) * aLen + 1);
	if (tmp_ret == NULL)
		perror("big segfult: "), exit(EXIT_FAILURE);

	strcpy(tmp_ret, tmp_arg);
	while(count != 0)
	{
		tmp_arg = va_arg(valist, char *), count--;	
		sLen = strlen(tmp_ret), aLen = strlen(tmp_arg);
		
		tmp_ptr = malloc(sizeof(char) * (sLen + aLen) + 1);
		if (tmp_ptr == NULL)
			perror("gros gros segfult: "), exit(EXIT_FAILURE);
		
		if (tmp_ret != NULL)
			strcpy(tmp_ptr, tmp_ret), free(tmp_ret);
		strcat(tmp_ptr, tmp_arg), tmp_ret = tmp_ptr;
	}

	va_end(valist);
	return (tmp_ret);
}
char *_strclear(char **dest)
{
	if (*dest == NULL)
		return (NULL);
	memset(*dest, 0, (strlen(*dest)));
	return (*dest);
}
/**
 *
 *
 */
char *_find_key_get_value(char **key_value, char *key)
{
    int i = 0;
	char *tmp;

    while (strstr(key_value[i], key) == NULL && key_value[i] != NULL)
        i++;

    if (key_value[i] == NULL)
        return (NULL);
	
	tmp = strstr(key_value[i], "="), tmp++;	
    return (tmp);
}
