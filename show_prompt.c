#include "shell.h"

/**
 * show_prompt - print the shell prompt
 */
void show_prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4);
}
