/*
** EPITECH PROJECT, 2019
** asm
** File description:
** h
*/

#ifndef ASM_H_
#define ASM_H_
#include "op.h"

typedef struct asm_t {
    struct header_s header;
    char *name;
    char *comment;
    char **inst;
} asm_t;

typedef struct inst_ck {
    char *str;
    int len;
    //char **(*fonc)(char **tab, char **env, save *sv);
} inst_t;

#endif
