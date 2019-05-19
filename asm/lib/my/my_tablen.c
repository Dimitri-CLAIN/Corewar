/*
** EPITECH PROJECT, 2019
** tablen
** File description:
** tablen
*/

#include <stddef.h>

int my_tablen(char **tab)
{
    int i = 1;

    if (tab[0] == NULL)
        return (0);
    while (tab[i] != NULL)
        i = i + 1;
    return (i);
}

int my_inttablen(int **tab)
{
    int i = 1;

    if (tab[0] == NULL)
        return (0);
    while (tab[i] != NULL) {
        i = i + 1;
    }
    return (i);
}
