/*
** EPITECH PROJECT, 2019
** inst
** File description:
** checker
*/

#include "my.h"

int label_checker(char *str)
{
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while (LABEL_CHARS[y] != '\0' || LABEL_CHARS[y] == str[i])
            y = y + 1;
        if (LABEL_CHARS[y] == '\0')
            return (84);
        y = 0;
    }
    return (0);
}

int  inst_checker(asm_t *a)
{
    for (int i = 0; i != a->cmd_nb; i++)
        if (my_tablen(a->cmd[i][0].inst) > MAX_ARGS_NUMBER)
            return (84);
    return (0);
}