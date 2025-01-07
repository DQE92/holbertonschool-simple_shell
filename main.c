#include "shell.h"

/**
 * main - Entry point for the shell
 * @argc: Numbers of arguments
 * @argv: Arguments array
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	char *program_name = argv[0];
	(void)argc;

	while (1)
	{

		if (isatty(STDIN_FILENO))
			show_prompt();

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (strlen(line) == 0)
			continue;

		if (strcmp(line, "exit") == 0)
		{
			break;
		}

		execute_command(line, program_name);
	}
	free(line);
	return (0);
}
