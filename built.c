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
 * Return: void
 */

void (*getbuilt_in(char **av))(char **av)
{
	built_in func[] = {
		{"exit", my_exit},
		{"env", _env},
		{NULL, NULL}
	};
	int i = 0;

	while (func[i].fun != NULL)
	{
		if (_strcmp(av[0], func[i].fun) == 0)
		{
			return (func[i].fp);
		}
		i++;
	}
	put_err(av[0]);
	return (0);
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
void _env(char **av __attribute__((unused)))
{
	int a;

	a = 0;
	while (environ[a])
	{
		_puts(environ[a]);
		_putchar('\n');
		a++;
	}
}

