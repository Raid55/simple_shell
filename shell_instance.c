#include "shell.h"
/**
 *
 *
 *
 *
 *
 *
 */
int _shell_instance()
{
	char *welcome = generate_prompt_line("BIT.SH");
	char *buffer = NULL, *pPath = NULL;
	char **t_args = NULL;
	ssize_t EOFCheck;
	unsigned int stat = 1;
	size_t getLineLen = 0;

	write(STDOUT_FILENO, welcome, strlen(welcome));
	EOFCheck = getline(&buffer, &getLineLen, stdin);
	
	if (EOFCheck == -1)
		stat = _SHELL_END_, write(STDOUT_FILENO, "\n", 1);
	if (EOFCheck == 1)
		stat = _SKIP_;

	if (stat == _NORMAL_)
		t_args = tokeniser(&buffer, " \n\t");

	if (stat == _NORMAL_)
		stat = run_built_in(t_args);

	if (stat == _NORMAL_)
		stat = _is_arg_run_ready(t_args[0]) ? _PATH_READY_ : _PATH_NREADY_;

	if (stat == _PATH_NREADY_)
		pPath = get_path_args(t_args[0]), stat = _PATH_READY_;

	if (stat == _PATH_READY_)
		exec_process(pPath ? pPath : t_args[0], t_args), wait(NULL);

		free(welcome);
		free(buffer);
		free(t_args);
		free(pPath);

	return (stat);
}

