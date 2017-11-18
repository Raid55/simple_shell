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
	
	if(welcome != NULL)
		free(welcome);
	if (buffer != NULL)
		free(buffer);
	if (t_args != NULL)
		free(t_args);
	if (pPath != NULL)
		free(pPath);
	
	return (stat);
}
char *generate_prompt_line(char *custom)
{
	if (custom == NULL)
		custom = "";

	return (_stralloc(21, 
				_BOLD_, _COLOR_MAGENTA_, custom, _CLEAR_,
				" | ",
				_COLOR_MAGENTA_, "Raid55", _CLEAR_,
				_BOLD_, _COLOR_GREEN_, "@", _CLEAR_,
				_BOLD_, _COLOR_YELLOW_, _find_env_get_value("USER"), _CLEAR_,
				":",
				_COLOR_CYAN_, _find_env_get_value("PWD"), _CLEAR_,
				"$ "));
}

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

	tmp = _find_env_get_value("PATH");
	tmp_args = tokeniser(&tmp, ":");
	tmp = _find_x_path(tmp_args, program);
	free(tmp_args);
	return (tmp);
}


