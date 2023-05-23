#include "main.h"

/**
 * put_err - prints error message
 * @cmd: command
 * Return: void
 */
void put_err(char *cmd)
{
	char sh[25] = "./hsh: ";

	_cat(sh, cmd);
	perror(sh);

}
