`
#include "shell.h"

/**
 * execute_command - Execute a command via execve
 * @command: command to execute
 */
void execute_command(char *command)
{
	extern char **environ;
	pid_t pid;
	int status;
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == -1) /* Gestion d'erreur pour fork */
	{
		perror(program_name);
		return;
	}
	else if (pid == 0) /* Processus enfant */
	{
		if (execve(command, args, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", program_name, command);
			exit(127); /* Commande introuvable */
		}
	}
	else /* Processus parent */
	{
		waitpid(pid, &status, 0); /* Attendre la fin du processus enfant */
	}
}
