#include "main.h"

/**
 * _len - finds string length
 * @str: string pointer
 * Return: length of string
 */
size_t _len(char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcopy - copies string from one buffer to the other
 * @dest: location to copy to
 * @src: buffer to copy from
 * Return: Nothing
 */
void _strcopy(char *dest, char *src)
{
	int i;

	if (src && dest)
	{
		for (i = 0; src[i] != '\0'; i++)
			dest[i] = src[i];
	}
	dest[i] = '\0';
}

/**
 * count_tok - Counts number of token
 * @input: pointer to input
 * Return: Number of token
 */
int count_tok(char *input)
{
	int i, cnt = 0;
	char *toks = NULL;

	if (!input)
		return (0);
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] > 32)
			break;
		return (0);
	}
	toks = strtok(input, " \n");
	while (toks != NULL)
	{
		cnt++;
		toks = strtok(NULL, " \n");
	}
	cnt++;
	return (cnt);

}

/**
 * tokenize - creates an array of tokens
 * @av: argument vector
 * @buf: input string
 * Return: void
 */
void tokenize(char *buf, char **av)
{
	char *tok;
	int i = 1, j = 0;

	if (buf)
	{
		if (av == NULL)
			perror("./hsh");
		else
		{
			tok = strtok(buf, " \n");
			while (tok !=  NULL)
			{
				av[j] = malloc(sizeof(char) * (_len(tok) + 1));
				_strcopy(av[j], tok);
				tok = strtok(NULL, " \n");
				j++;
			}
			av[j] = NULL;
			free(buf);
		}
		i = is_builtin(av);
		if (i == -1)
		{
			exec(av);
			free_av(av);
		}
		else
		{
			free_av(av);
		}
	}
}

/**
 * main - entry point a simple shell program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success else -1
 */
int main(int ac, char **av)
{
	char *input = NULL, *input_cpy = NULL;
	char prompt[] = "$ ";
	size_t size = 0;
	int char_read;

	while (1)
	{
		write(1, prompt, 2);
		char_read = getline(&input, &size, stdin);
		is_eof(char_read, input);
		input_cpy = malloc(sizeof(char) * char_read + 1);
		if (input_cpy == NULL)
		{
			perror("./hsh");
		}
		_strcopy(input_cpy, input);
		ac = count_tok(input);
		if (ac > 0)
		{
			av = malloc(ac * sizeof(char *));
			tokenize(input_cpy, av);
		}
	}
	return (0);
}
