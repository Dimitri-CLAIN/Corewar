/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** len
*/

#include <stddef.h>

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int array_len(char **tab)
{
    int i = 0;

    for (i = 0; tab[i] != NULL; i++);
    return (i);
}
