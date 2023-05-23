#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void exec(char *const av[]);
char *get_command(char *cmd_copy);
size_t _len(char *str);
void _strcopy(char *dest, char *src);
void is_eof(int stat, char *input);
void free_av(char **av);

#endif
