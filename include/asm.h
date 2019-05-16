/*
** EPITECH PROJECT, 2019
** asm
** File description:
** h
*/

#ifndef ASM_H_
#define ASM_H_
#include "op.h"

typedef struct arg_s {
    int size;
    char *arg;
} arg_t;

typedef struct coding_style {
    char *bin;
    int code;
    arg_t **arg;
} coding_style_t;

typedef struct s_command {
    char *name;
    coding_style_t *c_b;
    char **inst;
} command_t;

typedef struct asm_s {
    struct header_s header;
    char *name;
    char *comment;
    command_t **cmd;
} asm_t;

typedef struct inst_ck {
    char *str;
    int len;
    //char **(*fonc)(char **tab, char **env, save *sv);
} inst_t;

#endif
