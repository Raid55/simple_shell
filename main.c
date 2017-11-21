#include "shell.h"
/**
* main - entry point
* Return: 0 on success
*/
int main(void)
{
	unsigned int stat;

	do {
		stat = _shell_instance();
		if (stat == 3)
			stat = 0;
	} while (stat);

	return (0);
}
