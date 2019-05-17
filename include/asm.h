/*
** EPITECH PROJECT, 2019
** asm
** File description:
** h
*/

#ifndef _ASM_H_
#define _ASM_H_
#include "op.h"

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

typedef struct s_command {
    int pos;
    char *name;
    coding_style_t *c_b;
    char **inst;
} command_t;

typedef struct inst_ck {
    char *str;
    int len;
    //char **(*fonc)(char **tab, char **env, save *sv);
} inst_t;

typedef struct label_s {
    char *name_label;
    int position;
    arg_t **arg;
} label_t;

typedef struct asm_t {
    struct header_s header;
    char *name;
    char *comment;
    struct inst_ck *list;
    command_t **cmd;
    label_t **label;
    int cmd_nb;
    int p_s;
} asm_t;

#endif
