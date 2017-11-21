#include "shell.h"

/**
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
/**
 *
 *
 */
unsigned int _is_arg_run_ready(char *arg)
{
	if (access(arg, X_OK) == -1)
		return (0);
	else
		return (1);
}
/**
 *
 *
 *
 */
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
/**
 *
 *
 */
char *_find_env_get_value(char *key)
{
    int i = 0;
	char *tmp;

    while (strstr(environ[i], key) == NULL && environ[i] != NULL)
        i++;

    if (environ[i] == NULL)
        return (NULL);
	tmp = strstr(environ[i], "="), tmp++;	
    return (tmp);
}
/**
 *
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
		i++;
	}
	if (env_paths[i] == NULL)
		return (NULL);
	else
		return (tmp);
}
