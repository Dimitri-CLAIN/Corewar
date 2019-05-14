/*
** EPITECH PROJECT, 2019
** include
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "enum.h"

char *add_char(char *, char);
char *my_itohex(int, char *);
char **read_my_file(char *);

char *my_strcat(char *, char *);
int my_strlen_char(char *, char );
void my_putchar(char);
int my_strlen(char *);
int my_putstr(char const *);
int my_getnbr(char const *);
int my_put_nbr(int);
int my_strcmp(char *, char *);
char *my_strdup(char *);
char *my_revstr(char *, int );
char *my_clean_str(char *);
char **my_str_to_all_array(char *, char);
char *my_str_to_word_array_n(char *, char **);
void free_my_tab(char **);
char **my_clean_str_to_array(char *, char);

#endif
