/*
** EPITECH PROJECT, 2019
** my_str
** File description:
** cpy
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strcpy(char *str)
{
    int i = 0;
    char *out = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] != '\0') {
        out[i] = str[i];
        i = i + 1;
    }
    out[i] = '\0';
    return (out);
}