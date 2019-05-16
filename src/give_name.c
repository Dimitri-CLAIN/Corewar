/*
** EPITECH PROJECT, 2019
** give
** File description:
** name
*/

#include "my.h"

char *give_name(char *str)
{
    int last = 0;
    int nb_ext = 0;
    char *out = NULL;

    for (int nb = 0; str[nb] != '\0'; nb++)
        if (str[nb] == '/')
            last = nb;
    if (last != 0)
        last++;
    str = str + last;
    for (last = 0; str[last] != '\0' && str[last] != '.'; last++);
    if (str[last] == '\0')
        return (str);
    out = malloc(sizeof(char) * (last + 1));
    for (int z = 0; z != last; z++)
        out[z] = str[z];
    out[last] = '\0';
    return (out);
}