/*
** EPITECH PROJECT, 2019
** get arg
** File description:
** get all arg
*/

#include "my.h"

// Direct - Indirect -> peut etre un label

int check_flag(char *cmd, char *name, int flag, int pos)
{
    int n = 0;
    int x = 0;

    while (op_tab[n].mnemonique != 0
    && my_strcmp(name, op_tab[n].mnemonique) != TRUE)
        n++;
    while (op_tab[n].type[pos].type_arg[x] != 0) {
        if (op_tab[n].type[pos].type_arg[x] == flag)
            return (flag);
    }
    while (op_tab[n].type[pos].type_arg[x] != 0) {
        if (flag != T_REG && op_tab[n].type[pos].type_arg[x] == INDEXE)
            return (INDEXE);
    }
    return (flag);
}

char *take_arg(char *cmd, int n)
{
    char *arg = NULL;

    arg = my_strdup("");
    while (cmd[n] != '\0') {
        arg = add_char(arg, cmd[n]);
        n++;
    }
    return (arg);
}

void init_my_arg(int size, char *cmd, arg_t *arg, int flag)
{
    flag = check_flag(cmd, arg->name_cmd ,flag, arg->pos_arg);
    printf("[%d]\n", flag);
    arg->arg = take_arg(cmd, 1);
    if (flag == INDEXE || flag == T_LAB)
        arg->size = 2;
    arg->size = size;
    arg->state = flag;
}

void take_int(char **cmd, coding_style_t *c_d, char *name)
{
    int n = 0;
    int i = 0;

    c_d->arg = malloc(sizeof(arg_t) * (array_len(cmd) + 1));
    c_d->arg[array_len(cmd)] = NULL;
    while (cmd[n] != NULL) {
        c_d->arg[i] = malloc(sizeof(arg_t));
        c_d->arg[i]->pos_arg = i;
        c_d->arg[i]->name_cmd = name;
        if (cmd[n][0] == DIRECT_CHAR) {
            init_my_arg(DIR_SIZE, cmd[n], c_d->arg[i], n);
            i++;
        } else if (cmd[n][0] == 'r') {
            init_my_arg(1, cmd[n], c_d->arg[i], n);
            i++;
        } else {
            init_my_arg(IND_SIZE, cmd[n], c_d->arg[i], n);
            i++;
        }
        n++;
    }
}
