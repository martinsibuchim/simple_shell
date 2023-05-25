#include "main.h"

/**
 * m_getenv - gets environment variable
 * @env: varable to search for in environ
 * Return: pointer to environ variable or NULL
 */
char *m_getenv(const char *env)
{
	int a = 0, b;
	char *path = NULL;

	if (env == NULL)
		return (NULL);
	while (environ[a])
	{
		b = 0;
		if (env[b] == environ[a][b])
		{
			while (env[b])
			{
				if (env[b] != environ[a][b])
					break;
				b++;
			}
			if (env[b] == '\0')
			{
				b++;
				path = (environ[a] + b);
			}
		}
		a++;
	}
	return (path);
}

/**
 * getbuilt_in - gets builtin function
 * @av: argument vector
 * Return: 0 else -1
 */

int is_builtin(char **av)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		my_exit(av);
	}
	else if (_strcmp(av[0], "env") == 0)
	{
		_env(av);
		return (0);
	}
	return (-1);
}

/**
 * my_exit - exits a program
 * @av: argument vector
 * Return: void
 */
void my_exit(char **av)
{
	int a;

	if (av[1] == NULL)
	{
		free_av(av);
		av = NULL;
		exit(0);
	}
	else
	{
		a = _atoi(av[1]);
		if (a < 0)
			a = 2;
		free_av(av);
		av = NULL;
		exit(a);
	}
}

/**
 * _env - prints all environment vectors
 * @av: argument vector
 * Return: void
 */
void _env(char **av)
{
	int a;
	char err[70] = "./hsh: env: ";
	char *no = ": No such file or directory\n";

	if (av[1] == NULL)
	{
		a = 0;
		while (environ[a])
		{
			_puts(environ[a]);
			_putchar('\n');
			a++;
		}
	}
	if (av[1] != NULL)
	{
		_cat(err, av[1]);
		_cat(err, no);
		write(1, &err, _len(err));
		return;
	}
}
