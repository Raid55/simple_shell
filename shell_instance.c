#include "shell.h"
/**
 *
 *
 */
void _shell_instance(char **envp)
{
	size_t getLineLen = 0;
	char *buffer = NULL;
	char **t_args;
	char *welcome = "BIT.SH $ ";

	write(STDOUT_FILENO, welcome, 9);
	getline(&buffer, &getLineLen, stdin);

	t_args = tokeniser(&buffer, " \n\t");
	
	exec_process(t_args[0], t_args);
	wait(NULL);

	free(buffer);
	free(t_args);
}
