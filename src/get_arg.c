/*
** EPITECH PROJECT, 2019
** get arg
** File description:
** get all arg
*/

#include "my.h"

// Direct - Indirect -> peut etre un label

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

void init_my_arg(int size, char *cmd, arg_t *arg)
{
    arg->arg = take_arg(cmd, 1);
    arg->size = size;    
}

void take_int(char **cmd, coding_style_t *c_d)
{
    int n = 0;
    int i = 0;

    c_d->arg = malloc(sizeof(arg_t) * (array_len(cmd) + 1));
    c_d->arg[array_len(cmd)] = NULL;
    while (cmd[n] != NULL) {
        c_d->arg[i] = malloc(sizeof(arg_t));
        if (cmd[n][0] == DIRECT_CHAR) {
            init_my_arg(DIR_SIZE, cmd[n], c_d->arg[i]);
            i++;
        } else if (cmd[n][0] == 'r') {
            init_my_arg(1, cmd[n], c_d->arg[i]);
            i++;
        } else {
            init_my_arg(IND_SIZE, cmd[n], c_d->arg[i]);
            i++;
        }
        n++;
    }
}
