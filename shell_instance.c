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
	char **e_args = NULL;
	char *welcome = "BIT.SH $ ";
	char *pPath;
	int i = 0;

	write(STDOUT_FILENO, welcome, 9);
	getline(&buffer, &getLineLen, stdin);

	t_args = tokeniser(&buffer, " \n\t");

	if (access(t_args[0], X_OK) == -1)
    {
        pPath = find_key(envp, "PATH");
        /* printf("[afterFK: %s]\n", pPath); */
        e_args = tokeniser(&pPath, ":");
		/* while (e_args[i] != NULL) */
        	/* printf("[token: %s]\n", e_args[i++]); */
        pPath = get_x_path(e_args, t_args[0]);
        /* printf("[getPath: %s]\n", pPath); */
    }
    else
        pPath = t_args[0];	

	exec_process(pPath, t_args);
	wait(NULL);

	if (e_args != NULL)
		free(e_args);
	if (pPath != NULL)
		free(pPath);
	free(buffer);
	free(t_args);
}
