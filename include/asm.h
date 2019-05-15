/*
** EPITECH PROJECT, 2019
** asm
** File description:
** h
*/

#ifndef ASM_H_
#define ASM_H_

typedef struct asm_t {
    char *name;
    char *comment;
    char **inst;
} asm_t;

typedef struct inst_ck {
    char *str;
    int len;
    //char **(*fonc)(char **tab, char **env, save *sv);
} inst;

#endif /* !ASM_H_ */
