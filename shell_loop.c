#include "shell.h"
/**
 *
 */
void _shell_loop_init(char **envp)
{
	pid_t cPid;

	cPid = fork();
	if (cPid == -1)
		perror("Fork failed:"), exit(EXIT_FAILURE);
	
	if(cPid == 0)
		_shell_instance(envp), exit(EXIT_SUCCESS);
	wait(NULL);
	/* if () */
		_shell_loop_init(envp);
	/* else */
}
