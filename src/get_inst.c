/*
** EPITECH PROJECT, 2019
** get
** File description:
** inst
*/

#include "my.h"

inst_t test[] = {{"live", 4}, {"ld", 2}, {"st", 2}, {"add", 3}, {"sub", 3},
            {"and", 3}, {"or", 2}, {"xor", 3}, {"zjmp", 4} , {"ldi", 3},
            {"sti", 3}, {"fork", 4}, {"lld ", 3}, {"lldi", 4},
            {"lfork", 5}, {"aff", 3}};

char *cmd_name(char *file)
{
    int len = 0;
    int i = 0;
    char *out = NULL;

    while (file[len] >= 'a' && file[len] <= 'z')
        len++;
    out = malloc(sizeof(char) * (len + 1));
    while (i != len) {
        out[i] = file[i];
        i = i + 1;
    }
    out[i] = '\0';
    return (out);
}

int check_val_pos(int pos, int name, int comment)
{
    if (pos > name && pos > comment)
        return (0);
    return (84);
}

int cmd_len(char **file, asm_t *a)
{
    int len = 0;
    char *cmp = NULL;

    if (file == NULL)
        return (84);
    for (int i = 0 ; file[i] ; i++) {
        cmp = cmd_name(file[i]);
        for (int y = 0 ; y != 16 ; y++) {
            my_strcmp(cmp, test[y].str) == TRUE ? len = len + 1 : 0;
        }
        free(cmp);
    }
    return (len);
}

command_t **takecmd_name(char **file, asm_t *a)
{
    int j = 0;
    char *cmp = NULL;

    if (file == NULL)
        return (a->cmd);
    for (int i = 0 ; file[i] ; i++) {
        cmp = cmd_name(file[i]);
        for (int y = 0 ; y != 16 ; y++) {
            my_strcmp(cmp, test[y].str) == TRUE ?
            a->cmd[j][0].name = my_strcpy(cmp), j = j + 1 : 0;
        }
        free(cmp);
    }
    return (a->cmd);
}

int get_inst(char **file, asm_t *a, int name, int comment)
{
    a->cmd_nb = cmd_len(file, a);
    a->cmd = malloc(sizeof(command_t *) * (a->cmd_nb + 1));
    for (int i = 0; i != a->cmd_nb ; i++)
        a->cmd[i] = malloc(sizeof(command_t));
    a->cmd[a->cmd_nb] = NULL;
    a->cmd = takecmd_name(file, a);
    a->cmd = takecmd_inst(file, a);
}
