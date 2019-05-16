/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** string_allocation
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

char *my_cpy(char *str, char *src)
{
    int nb = 0;

    while (src[nb] != '\0') {
        str[nb] = src[nb];
        nb = nb + 1;
    }
    return (str);

}

char *my_strdup(char *src)
{
    char *str = NULL;
    int a = my_strlen(src);

    str = malloc(sizeof(char) * (a + 1));
    str[a] = '\0';
    my_cpy(str, src);
    return (str);
}
