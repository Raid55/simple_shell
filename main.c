#include "shell.h"
/**
 *
 */
int main(int ac, char **av, char **envp)
{
	(void) ac;
	(void) av;

	_shell_loop_init(envp);

	return(0);
}
