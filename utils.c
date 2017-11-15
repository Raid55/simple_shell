#include "shell.h"
/**
 *
 */
char **tokeniser(char **buff, char *pattern)
{
	int i;
    char *tok;
	char **_argv;

    tok = strtok(*buff, pattern);
    if (tok == NULL)
    	perror("no command passed: "), exit(0);
	_argv = malloc(sizeof(char *) * 2);
    if (_argv == NULL)
        perror("Error in Allocation: "), exit(2);
    i = 1, _argv[0] = tok;

    while (tok != NULL)
    {
        tok = strtok(NULL, pattern);
        if (tok != NULL)
        {
        	_argv = realloc(_argv, sizeof(char *) * (i + 2));
            if (_argv == NULL)
            	free(buff), perror("Error in Allocation: "), exit(2);
            _argv[i++] = tok;
    	}
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

	pathCount = strlen(env_paths[0]);
	tmp = malloc(sizeof(char) * (strlen(env_paths[0]) + pCount) + 2);
	if (tmp == NULL)
		perror("grosse alert la...alert rouge, segfult!: "), exit(EXIT_FAILURE);
	
	tmp = memset(tmp, 0, (pathCount + pCount) + 2);
	strcpy(tmp, env_paths[0]);
	strcat(tmp, "/");
	strcat(tmp, program);

	while (access(tmp, X_OK) == -1 && env_paths[i] != NULL)
	{
		pathCount = strlen(env_paths[i]);
		tmp = realloc(tmp, sizeof(char) * (pathCount + pCount) + 2);
		if (tmp == NULL)	
			perror("gros gros segfult: "), exit(EXIT_FAILURE);

		tmp = memset(tmp, 0, (pathCount + pCount) + 2);
		strcpy(tmp, env_paths[i]);
		strcat(tmp, "/");
		strcat(tmp, program);
		/* printf("[inloop: %s]\n", tmp); */
		i++;
	}
	if (env_paths[i] == NULL)
	{
		/* rintf("heyaa"); */
		return (NULL);
	}
	else
		return (tmp);
}
char *_strealloc(char **dest, ...)
{
	va_list valist;
	char *tmp;
	int sLen;
	int dLen;

	va_start(valist, dest);
	if (*dest == NULL)
		return (NULL);
	
	tmp = va_arg(valist, char *);
	while(tmp != NULL)
	{
		dLen = strlen(*dest), sLen = strlen(tmp);
		*dest = realloc(*dest, sizeof(char) * (dLen + sLen) + 1);
		if (*dest == NULL)
			perror("gros gros segfult: "), exit(EXIT_FAILURE);
		strcat(*dest, tmp);
		tmp = va_arg(valist, char *);
	}

	va_end(valist);
	return (*dest);
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
/* char *strealloc(char *start, char *addon) */
/* { */

/* } */
