#include "shell.h"
/**
 * _shell_instance - and instance of the shell
 * Return: status code
 */
int _shell_instance(void)
{
	/* char *welcome = generate_prompt_line("BIT.SH"); */
	char *buffer = NULL, *pPath = NULL;
	char **t_args = NULL;
	ssize_t EOFCheck;
	unsigned int stat = 1;
	size_t getLineLen = 0;

	write(STDOUT_FILENO, "$ ", 2);
	/* signal(SIGINT, SIG_IGN); */
	EOFCheck = getline(&buffer, &getLineLen, stdin);

	if (EOFCheck == -1)
		stat = _SHELL_END_, write(STDOUT_FILENO, "\n", 1);
	if (EOFCheck == 1)
		stat = _SKIP_;

	if (stat == _NORMAL_)
		t_args = tokeniser(&buffer, "' '\n\t");
	/* printf("LOLOLO[%s]\n", t_args[0]); */
	if (stat == _NORMAL_)
		stat = run_built_in(t_args);

	if (stat == _NORMAL_ && t_args[0][0] != '.')
		pPath = get_path_args(t_args[0]);
	if (stat == _NORMAL_)
		exec_process(pPath ? pPath : t_args[0], t_args), wait(NULL);

		/* free(welcome); */
		free(buffer);
		free(t_args);
		free(pPath);

	return (stat);
}

