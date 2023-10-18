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

int _strlen(const char *s);
void check_end(char *end, char *inp_ask);
void exec_child(char *tok_ask, char *ags_ask[], int i);
void create_ps(char *inp_ask);

#endif /* MAIN_H */
