/*
** EPITECH PROJECT, 2019
** val
** File description:
** check
*/

#include "my.h"

int type_checker()
{

}

int val_inst(command_t cmd)
{
    int i = 0;
    int error = 0;

    for (i = 0; i != 17 &&
        my_strcmp(cmd.name, op_tab[i].mnemonique) != TRUE; i++);
    if (i == 17)
        return (84);
    if (my_tablen(cmd.inst) != op_tab[i].nbr_args ||
        op_tab[i].nbr_args > MAX_ARGS_NUMBER)
        return (84);
    for (int y = 0; op_tab[i].type[y].type_arg[x] != 0 || error == 84; y++)
        error = type_checker(op_tab[i].type[y].type_arg[x], cmd.inst[y]);
    if (error == 84)
        return (84);
    return (0);
}