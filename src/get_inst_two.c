/*
** EPITECH PROJECT, 2019
** inst
** File description:
** check
*/

#include "my.h"

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