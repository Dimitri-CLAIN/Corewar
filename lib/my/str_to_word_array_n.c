/*
** EPITECH PROJECT, 2019
** strto
** File description:
** n char
*/

#include "../../include/my.h"

char *my_str_to_word_array_n(char *str, char **tmp)
{
    char *dest = NULL;

    str += my_strlen(tmp[0]);
    dest = my_strdup(str);
    free(tmp);
    return (dest);
}