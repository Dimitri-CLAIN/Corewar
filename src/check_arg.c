/*
** EPITECH PROJECT, 2019
** check_arg
** File description:
** check_arg
*/

#include "my.h"

char *take_arg(char *cmd, int n)
{
    char *arg = NULL;

    arg = my_strdup("");
    while (cmd != NULL && cmd[n] != '\0') {
        if (cmd[n] != LABEL_CHAR)
            arg = add_char(arg, cmd[n]);
        n++;
    }
    return (arg);
}