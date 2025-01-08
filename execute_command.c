#include "shell.h"
#include <string.h> /* Pour strtok */
#include <sys/stat.h> /* Pour struct stat et access */

/**
 * find_command - Search for a command in the PATH
 * @command: Command to search for
 * Return: Full path to the command if found, NULL otherwise
 */
char *find_command(char *command)
{
    char *path, *dir, *full_path;
    struct stat st;

    /* Vérifier si la commande est un chemin absolu ou relatif */
    if (command[0] == '/' || command[0] == '.')
    {
        if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR)) /* Commande exécutable */
            return strdup(command);
        return NULL;
    }

    /* Récupérer la variable d'environnement PATH */
    path = getenv("PATH");
    if (!path)
        return NULL;

    /* Parcourir chaque répertoire dans PATH */
    path = strdup(path); /* Copier PATH car strtok modifie la chaîne */
    dir = strtok(path, ":");
    while (dir != NULL)
    {
        /* Construire le chemin complet : dir/command */
        full_path = malloc(strlen(dir) + strlen(command) + 2);
        if (!full_path)
            break;
        sprintf(full_path, "%s/%s", dir, command);

        /* Vérifier si le fichier est exécutable */
        if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
        {
            free(path); /* Libérer PATH avant de retourner */
            return full_path;
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path); /* Libérer PATH */
    return NULL;
}

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
    char *full_path;
    int i = 0;

    /* Découper la commande en arguments avec strtok */
    char *token = strtok(command, " ");
    while (token != NULL && i < 1023)
    {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;

    if (args[0] == NULL) /* Si aucune commande n'a été saisie, retourner */
        return;

    /* Trouver le chemin complet de la commande */
    full_path = find_command(args[0]);
    if (full_path == NULL) /* Commande introuvable */
    {
        fprintf(stderr, "%s: %s: command not found\n", program_name, args[0]);
        return;
    }

    pid = fork();
    if (pid == -1) /* Gestion d'erreur pour fork */
    {
        perror(program_name);
        free(full_path);
        return;
    }
    else if (pid == 0) /* Processus enfant */
    {
        if (execve(full_path, args, environ) == -1) /* Exécuter la commande */
        {
            perror(program_name); /* Afficher une erreur en cas d'échec */
            free(full_path);
            exit(127);
        }
    }
    else /* Processus parent */
    {
        waitpid(pid, &status, 0); /* Attendre la fin du processus enfant */
    }

    free(full_path); /* Libérer le chemin complet */
}
