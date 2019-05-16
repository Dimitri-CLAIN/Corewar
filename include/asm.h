/*
** EPITECH PROJECT, 2019
** asm
** File description:
** h
*/

#ifndef ASM_H_
#define ASM_H_
#include "op.h"

typedef struct inst_ck {
    char *str;
    int len;
    //char **(*fonc)(char **tab, char **env, save *sv);
} inst_t;

typedef struct command_t {
    char *name;
    int cooding_byte;
    char **inst;
} command_t;

typedef struct asm_t {
    struct header_s header;
    char *name;
    char *comment;
    struct inst_ck *list;
    command_t *cmd;
    int cmd_nb;
} asm_t;

#endif
