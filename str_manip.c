#include "main.h"

/**
 * _puts - writes string to stdout
 * @s: pointer to string
 *
 * Return: void
 */
void _puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
}

/**
 * _putchar - writes a character to stdout
 * @c: character
 * Return: 0 on success else -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * put_err - prints error message
 * @cmd: command
 * Return: void
 */
void put_err(char *cmd)
{
	char sh[40] = "./hsh: ";

	_cat(sh, cmd);
	perror(sh);

}

/**
 * _atoi - convert string to int
 * @s: string pointer
 * Return: integer
 */
int _atoi(char *s)
{
	int num = 0;
	int sign = 1;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');
		else
			break;
	} while (*s++);
	num *= sign;

	return (num);
}

/**
 * _strcmp - compares two strings
 * @s1: pointer to 1st string
 * @s2: pointer to second string
 * Return: 0 is both are equal, positive is 1st diff char > in s1 else negative
 */

int _strcmp(char *s1, char *s2)
{
	int i, retv = 0;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			retv = s1[i] - s2[i];
			break;
		}
	}
	return (retv);
}
