/*
** EPITECH PROJECT, 2019
** sv
** File description:
** cmd
*/

#include "my.h"

void sv_cmd_two(asm_t *a, char *cmp, int *j)
{
    if (cmp[0] != COMMENT_CHAR && check_label(cmp) == TRUE) {
        a->cmd[(*j)] = set_label(cmp, a);
        (*j) = (*j) + 1;
    } else if (cmp[0] != '\0' &&
    cmp[0] != COMMENT_CHAR && check_inst(cmp) == TRUE) {
        a->cmd[(*j)] = set_inst(cmp, a);
        (*j) = (*j) + 1;
    }
}

void sv_cmd(char **file, asm_t *a, int name, int comment)
{
    char *cmp = NULL;
    int j = 0;

    for (int i = 0; file[i] != NULL; i++) {
        cmp = my_clean_str(file[i]);
        sv_cmd_two(a, cmp, &j);
        free(cmp);
    }
    a->cmd[j] = NULL;
    a->p_s = (a->cmd[j - 1]->pos + 2);
}