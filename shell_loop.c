#include "shell.h"
/**
 *
 */
void _shell_loop_init(char **envp)
{
	pid_t cPid;

	cPid = fork();
	if (cPid == -1)
		perror("Fork failed:"), exit(-1);
	
	if(cPid == 0)
		_shell_instance(envp), exit(1);
	else
		wait(NULL), _shell_loop_init(envp);
}
