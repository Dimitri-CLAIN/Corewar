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
#include "asm.h"
#include "enum.h"
char *my_memset(char *str, int size, char c);

char *add_char(char *, char);
char *my_itohex(int, char *);
char **read_my_file(char *);
coding_style_t *search_coding_byte(char **, asm_t *, char *);
int detect_my_cmd(char *);
char *my_bintohex(char *);
int create_my_bin(asm_t *, char *);
int big_to_little_endian(int, int);
int my_bintoi(char *);
void take_int(char **, coding_style_t *, char *);
void int_cmd_pos(command_t *);
char *take_arg(char *, int);
int label_to_funct(char *, command_t **, int);
void search_label(command_t **);
int check_bin(char *);

int array_len(char **);
char *my_itoa(int);
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
int my_strncmp(char *s1, char *s2, int nb);
char *my_strcpy(char *str);
int check_file(char **file, asm_t *a);
int get_inst(char **file, asm_t *a, int name, int comment);
int  inst_checker(asm_t *a);
void list_create(asm_t *a);
command_t **takecmd_inst(char **file, asm_t *a);
char *cmd_name(char *file);
int bad_line_checker(char **file, asm_t *a, int name, int comment);
void my_puttab(char **tab, char sep);
int my_tablen(char **tab);
int label_checker(char *str);
char *give_name(char *str);
int my_live(command_t a);
int get_labels(char **file, asm_t *a);
int get_cmd(char **file, asm_t *a, int name, int comment);
void sv_cmd(char **file, asm_t *a, int name, int comment);
int check_label(char *);
int check_inst(char *str);
int val_inst(command_t cmd, asm_t *info);
int check_flag(char *cmd, char *name, int flag, int pos);
int check_label_char(char c);
int val_label(command_t cmd, asm_t *info);
int my_live(command_t a);
void set_struct_command(command_t *out);
command_t *set_label(char *line, asm_t *info);
command_t *set_inst(char *line, asm_t *info);

#endif
