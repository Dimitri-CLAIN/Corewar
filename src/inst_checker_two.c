/*
** EPITECH PROJECT, 2019
** inst_checker
** File description:
** two
*/

#include "my.h"

int check_label_char(char c)
{
    int i = 0;

    for (i = 0; LABEL_CHARS[i] != '\0'; i++) {
        if (LABEL_CHARS[i] == c)
            return (0);
    }
    return (84);
}

int my_live(command_t a)
{
    if (my_strcmp(a.name, op_tab[0].mnemonique) == FALSE)
        return (84);
    if (my_tablen(a.inst) != op_tab[0].nbr_args)
        return (84);
    return (0);
}