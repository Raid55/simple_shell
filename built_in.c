#include "shell.h"

int run_built_in(char **args)
{
	int i = 0;
	b_ins binsarr[] = {
		{"env", _bin_env},
		{"exit", _bin_exit},
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
	return (2);
}

int _bin_exit(char **args)
{
	return(3);
}
