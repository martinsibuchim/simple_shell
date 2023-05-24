#include "main.h"

/**
 * free_av - freea argc
 * @av: location to free
 * Return: void
 */
void free_av(char **av)
{
	int i;

	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
}

/**
 * is_eof - checks for ctrl D
 * @stat: checks status
 * @input: user input
 * Return: Nothing
 */
void is_eof(int stat, char *input)
{
	char c = '\n';

	if (stat == -1)
	{
		if (input)
			free(input);
		write(1, &c, 1);
		exit(-1);
	}
}

/**
 * _cat - concatenates string
 * @dest: location to concatenate string to
 * @src: srting to concatenate
 * Return: void
 */
void _cat(char *dest, char *src)
{
	int i, j, k;

	for (i = 0; dest[i] != '\0'; i++)
	{}
	for (j = 0; src[j] != '\0'; j++)
	{}
	for (k = 0; k <= j; k++)
		dest[i + k] = src[k];
	dest[i + k] = '\0';

}

/**
 * get_command - gets command location
 * @cmd: user input command
 * Return: address of command location
 */
char *get_command(char *cmd)
{
	struct stat buf;
	char *location = NULL, *loc_copy = NULL, *token, *file;
	int dir_len = 0, cmd_len = 0;

	if (stat(cmd, &buf) == 0)
		return (cmd);
	location = m_getenv("PATH");
	if (location)
	{
		loc_copy = malloc(sizeof(char) * _len(location) + 1);
		if (loc_copy == NULL)
		{
			perror("./shell");
			return (NULL);
		}
		_strcopy(loc_copy, location);
		cmd_len = _len(cmd);
		token = strtok(loc_copy, ":");
		while (token != NULL)
		{
			dir_len = _len(token);
			file = malloc(2 + dir_len + cmd_len);
			_strcopy(file, token);
			_cat(file, "/");
			_cat(file, cmd);
			if (stat(file, &buf) == 0)
			{
				free(loc_copy);
				return (file);
			}
			else
			{
				free(file);
				token = strtok(NULL, ":");
			}
		}
		free(loc_copy);
		return (NULL);
	}
	return (NULL);
}

/**
 * exec - executes a command
 * @av: command arguments
 * Return: 0 on sucess else -1
 */
void exec(char *const av[])
{
	pid_t pid;
	char *cmd, *dup_cmd = NULL;

	if (av != NULL)
	{
		dup_cmd = av[0];
		cmd = get_command(dup_cmd);
		if (cmd)
		{
			pid = fork();
			if (pid == -1)
				perror("./shell");
			if (pid == 0)
			{
				if (execve(cmd, av, NULL) == -1)
					perror(cmd);
				free(cmd);
				exit (0);
			}
			else
			{
				wait(NULL);
				free(cmd);
			}
		}
		else
		{
			put_err(av[0]);
		}
	}
}
