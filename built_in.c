#include "shell.h"

int run_built_in(char **args)
{
	int i = 0;
	b_ins binsarr[] = {
		{"env", _bin_env},
		{"exit", _bin_exit},
		{"cd", _bin_cd},
		{NULL, NULL}
	};
	
	while (binsarr[i].command != NULL)
	{
		if (strcmp(args[0], binsarr[i].command) == 0)
			return(binsarr[i].func(args));
		i++;
	}
	return (1);
}

int _bin_env(char **args)
{
	(void) args;
	int i = 0, len;

	while (environ[i] != NULL)
	{
		len = strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (2);
}

int _bin_exit(char **args)
{
	return(3);
}

int _bin_cd(char **args)
{
	if (args[1] == NULL)
		perror("BIT.SH: expected argument to \"cd\"\n");
	else
		if (chdir(args[1]) == -1)
			perror("BIT.SH");
	return (2);
}
