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
void put_err(char *cmd);
void _cat(char *dest, char *src);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
void my_exit(char **av);
void _env(char **envp);
int _putchar(char c);
void _puts(char *s);
char *m_getenv(const char *env);
int is_builtin(char **av);

extern char **environ;

#endif
