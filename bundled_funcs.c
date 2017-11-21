#include "shell.h"

/**
 *
 *
 *
 */
char *get_path_args(char *program)
{
	char *tmp;
	char *tmp_env;
	char **tmp_args;

	tmp = _find_env_get_value("PATH");
	/* printf("%s\n", tmp); */
	tmp_env = _stralloc(1, tmp);
	tmp_args = tokeniser(&tmp_env, ":");
	/* printf("[%s]\n", tmp_args[1]); */
	tmp = _find_x_path(tmp_args, program);
	/* printf("tmp[%s]a1[]a2[]\n", tmp); */
	free(tmp_env);
	free(tmp_args);
	return (tmp);
}

char *generate_prompt_line(char *custom)
{
	char buff[1024];

	if (custom == NULL)
		custom = "";

	return (_stralloc(21, 
				_BOLD_, _COLOR_MAGENTA_, custom, _CLEAR_,
				" | ",
				_COLOR_MAGENTA_, "Raid55", _CLEAR_,
				_BOLD_, _COLOR_GREEN_, "@", _CLEAR_,
				_BOLD_, _COLOR_YELLOW_, _find_env_get_value("USER"), _CLEAR_,
				":",
				_COLOR_CYAN_, getcwd(buff, 1024), _CLEAR_,
				"$ "));
}
