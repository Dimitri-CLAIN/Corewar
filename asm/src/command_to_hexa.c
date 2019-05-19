/*
** EPITECH PROJECT, 2019
** commande to hexa
** File description:
** commande to hexa
*/

#include "my.h"
#include "op.h"

int detect_my_cmd(char *cmd)
{
    if (cmd[0] == 'r')
        return (REGISTER);
    if (cmd[0] == '%')
        return (DIRECT);
    if (my_getnbr(cmd) != -1)
        return (INDIRECT);
    return (FALSE);
}
