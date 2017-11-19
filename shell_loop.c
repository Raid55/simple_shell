#include "shell.h"
/**
 *
 */
void _shell_loop_init()
{
	unsigned int stat;

	do {
		stat = _shell_instance();
		if (stat == 3)
			stat = 0;
	} while (stat);
}
