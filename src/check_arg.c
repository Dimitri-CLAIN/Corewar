/*
** EPITECH PROJECT, 2019
** check_arg
** File description:
** check_arg
*/

#include "my.h"

int check_label(command_t *cmd)
{
    int n = 0;

    while (cmd->inst[1][n] != '\0') {
        if (cmd->inst[1][n] == LABEL_CHAR)
            return (TRUE);
        n++;
    }
    return (FALSE);
}

// int check_label_or_inst(asm_t *info, command_t *cmd)
// {
//     int state = 0;

//     if (check_label(cmd) == FALSE) {
//         cmd->c_b = search_coding_byte(cmd->inst, info);
//         take_int(cmd->inst, cmd->c_b, cmd->name);
//     } else {
//         label_d = malloc(sizeof(label_t *));
//         label_d->c_b = search_coding_byte(cmd->inst, info);
//         take_int(cmd->inst, label_d->c_b, cmd->name);
//         label_d->name_label = cmd->name;
//         label = label_d;
//         state = 1;
//     }
//     return (state);
//     // verifier si c'est une commande ou un label, si c'est un label, on doit
//     // commencer a partire du suivant;
//     // faire une structure label, a chaque vue d'un label, on ecrie dans une struct,
//     // dans la structure on a le label(char *), position(int), la commande quelle fait
// }

char *take_arg(char *cmd, int n)
{
    char *arg = NULL;

    arg = my_strdup("");
    while (cmd[n] != '\0') {
        if (cmd[n] != LABEL_CHAR)
            arg = add_char(arg, cmd[n]);
        n++;
    }
    return (arg);
}