/*
** EPITECH PROJECT, 2019
** asm
** File description:
** h
*/

#ifndef ASM_H_
#define ASM_H_
#include "op.h"
#include "my.h"

typedef struct arg_s {
    char *name_cmd;
    int size;
    int pos_arg;
    char *arg;
    int state;
} arg_t;

typedef struct coding_style {
    char *bin;
    int code;
    arg_t **arg;
} coding_style_t;

typedef struct s_command command_t;

typedef struct labels {
    char *name;
    command_t **cmd;
    int pos;
} labels_t;

struct s_command {
    int state;
    int pos;
    char *name;
    coding_style_t *c_b;
    char **inst;
    labels_t labels;
};

typedef struct inst_ck {
    char *str;
    int len;
    int (*fonc)(command_t a);
} inst_t;

typedef struct asm_t {
    struct header_s header;
    char *name;
    char *comment;
    struct inst_ck *list;
    command_t **cmd;
    int cmd_nb;
    int p_s;
} asm_t;

#endif
