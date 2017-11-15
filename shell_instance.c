#include "shell.h"
/**
 *
 *
 *stat 0: all clear
 *stat 1: continue loop, skip rest
 *stat 2: end of file
 *stat 3: built-in
 *stat 4: not path ready
 *stat 5: path ready
 */
int _shell_instance()
{
	size_t getLineLen = 0;
	char *buffer = NULL;
	char **t_args = NULL;
	char *welcome = "BIT.SH $ ";
	char *pPath = NULL;
	ssize_t EOFCheck;
	unsigned int stat = 1;
	
	write(STDOUT_FILENO, welcome, 9);
	EOFCheck = getline(&buffer, &getLineLen, stdin);
		
	if (EOFCheck == -1)
		stat = _SHELL_END_;
	if (EOFCheck == 1)
		stat = _SKIP_;
		
	if (stat == _CLEAR_)
		t_args = tokeniser(&buffer, " \n\t");
	
	if (stat == _CLEAR_)
		stat = run_built_in(t_args);
	
	if (stat == _CLEAR_)
		stat = _is_arg_run_ready(t_args[0]) ? _PATH_READY_ : _PATH_NREADY_;
	
	if (stat == _PATH_NREADY_)
		pPath = get_path_args(t_args[0]), stat = _PATH_READY_;
	
	if (stat == _PATH_READY_)
		exec_process(pPath ? pPath : t_args[0], t_args), wait(NULL);
	
	if (buffer != NULL)
		free(buffer);
	if (t_args != NULL)
		free(t_args);
	if (pPath != NULL)
		free(pPath);
	
	return (stat);
}
/* char *generate_prompt_line(char **envp, char *custom) */
/* { */


/* } */

unsigned int _is_arg_run_ready(char *arg)
{
	if (access(arg, X_OK) == -1)
		return (0);
	else
		return (1);
}

char *get_path_args(char *program)
{
	char *tmp;
	char **tmp_args;

	tmp = _find_key_get_value(environ, "PATH");
	tmp_args = tokeniser(&tmp, ":");
	tmp = _find_x_path(tmp_args, program);
	free(tmp_args);
	return (tmp);
}

/* int is_built_in */
