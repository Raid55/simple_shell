#include "shell.h"
/**
 *
 */
void _shell_loop_init()
{
	pid_t cPid;
	unsigned int stat;
	int waitStat;

	cPid = fork();
	if (cPid == -1)
		perror("Fork failed:"), exit(EXIT_FAILURE);
	
	if(cPid == 0)
	{
		stat = _shell_instance();
		switch(stat)
		{
			case 1:
			case 2:
			case 4:
			case 5:
			case 6:
				exit(1);
				break;
			case 0:
			case 3:
				exit(0);
				break;
			default:
				exit(1);
		}
	}

	wait(&waitStat);
	stat = WEXITSTATUS(waitStat);
	if (stat)	
		_shell_loop_init();
	else
		return;
}
