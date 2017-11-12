#include "shell.h"
/**
 *
 */
char **tokeniser(char **buff, char *pattern)
{
	int i;
    char *tok;
	char **_argv;

    tok = strtok(*buff, pattern);
    if (tok == NULL)
    	perror("no command passed: "), exit(0);
	_argv = malloc(sizeof(char *) * 2);
    if (_argv == NULL)
        perror("Error in Allocation: "), exit(2);
    i = 1, _argv[0] = tok;

    while (tok != NULL)
    {
        tok = strtok(NULL, pattern);
        if (tok != NULL)
        {
        	_argv = realloc(_argv, sizeof(char *) * (i + 2));
            if (_argv == NULL)
            	free(buff), perror("Error in Allocation: "), exit(2);
            _argv[i++] = tok;
    	}
    }
    _argv[i] = NULL;
    return(_argv);
}
/**
 *
 *
 */
void exec_process(char *program, char **e_args)
{
        pid_t cPid;

        cPid = fork();
        if (cPid == -1)
                perror("twas the night before xmas and fork faild"), exit(-1);
        /*if child process*/
        if (cPid == 0)
                if (execve(program, e_args, NULL) == -1)
                	perror("Error in running program:"), exit(2);
}
/**
 *
 *
 */
char *get_x_path(char **env_paths, char *program)
{
	int i = 1;
	int pCount = strlen(program);
}
void  _get_x_path(char **env_paths, char *program, char **tmp_path)
{
        int i = 1;
        char *tmp;
        int pCount = strlen(program);

        tmp = malloc(sizeof(char) * (strlen(env_paths[0]) + pCount) + 1);
        if (tmp == NULL)
                perror("grosse error alert rouge, segfult!: "), exit(-1);
        tmp[0] = '\0';
        strcpy(tmp, env_paths[0]);
        strcat(tmp, program);
        tmp[strlen(env_paths[0]) + pCount] = '\0';
        while (access(tmp, X_OK) == -1 || env_paths[i] != NULL)
        {
                tmp = realloc(tmp, sizeof(char) * (strlen(env_paths[i]) + pCount) + 1);
                if (tmp == NULL)
                        perror("due gros problem, segbut!!!: "), exit(-1);
                tmp[0] = '\0';
                strcpy(tmp, env_paths[i]);
                strcat(tmp, program);
                tmp[strlen(env_paths[i] + pCount)] = '\0', i++;
        }
        if (env_paths[i] == NULL)
                free(tmp), *tmp_path = NULL;
        else
                *tmp_path = tmp;
}
/**
 *
 *
 */
char *find_key(char **key_value, char *key)
{
        int i = 0;

        while (strstr(key_value[i], key) == NULL && key_value[i] != NULL)
                i++;

        if (key_value[i] == NULL)
                return (NULL);
        else
                return (strstr(key_value[i], "/"));
}
