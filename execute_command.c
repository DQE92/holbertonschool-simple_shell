#include "shell.h"
#include <string.h> /* Pour strtok */

/**
 * execute_command - Execute a command via execve
 * @command: Command to execute
 * @program_name: Name of the main program
 */
void execute_command(char *command, char *program_name)
{
	pid_t pid;
	int status;
	char *args[1024]; /* Tableau pour stocker les arguments (limité à 1024) */
	int i = 0;

	/* Découper la commande en arguments avec strtok */
	char *token = strtok(command, " ");

	while (token != NULL && i < 1023) /* Limiter le nombre d'arguments à 1023 */
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL; /* Le dernier élém du tab doit être NULL pour execve */

	if (args[0] == NULL) /* Si aucune commande n'a été saisie, retourner */
		return;

	pid = fork();
	if (pid == -1) /* Gestion d'erreur pour fork */
	{
		perror(program_name);
		return;
	}
	else if (pid == 0) /* Processus enfant */
	{
		if (execve(args[0], args, environ) == -1) /* Exécuter la commande */
		{
			/* Si execve échoue, afficher une erreur et quitter avec code 127 */
			fprintf(stderr, "%s: No such file or directory\n", program_name);
			exit(127);
		}
	}
	else /* Processus parent */
	{
		waitpid(pid, &status, 0); /* Attendre la fin du processus enfant */
	}
}
