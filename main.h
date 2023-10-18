#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define NULL ((void *)0)
extern char **environ;

int _strlen(const char *s);
void check_end(char *end, char *inp_ask);
void exec_child(char *tok_ask, char *ags_ask[], char *inp_ask);
void create_ps(char *inp_ask);
int _strncmp(const char *str1, const char *str2, size_t num_sk);
int print_str(char *str);
char *_getenv(const char *name);
int _putchar(char c);
char *get_path(const char *inp_ask, const char *path_ask);
char *_strdup(const char *s1);

#endif /* MAIN_H */
