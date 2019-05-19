/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** array_to_double_array
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

char **my_arraylo(char **array, char *str, char c)
{
    int i = 0;
    int x = 0;
    int compt = 0;

    while (str[i] != '\0') {
        if (c != str[i]) {
            i++;
            compt++;
        } else if (c == str[i]) {
            array[x] = malloc(sizeof(char *) * (compt + 1));
            x++;
            i++;
            compt = 0;
        } else
            i++;
    }
    array[x] = malloc(sizeof(char *) * (compt + 1));
    return (array);
}

char **my_farraazy(char **array, char *str, char c)
{
    int i = 0;
    int x = 0;

    while (str[i] != '\0') {
        if (c != str[i]) {
            x++;
            i++;
        }
        else
            i++;
    }
    x++;
    array = malloc(sizeof(char *) * (x + 1));
    return (array);
}

char **my_insert_arraay(char **array, char *str, char c)
{
    int i = 0;
    int x = 0;
    int compt = 0;

    while (str[i] != '\0') {
        if (c != str[i]) {
            array[x][compt] = str[i];
            i++;
            compt++;
        } else if (c == str[i]) {
            array[x][compt] = '\0';
            compt = 0;
            x++;
            i++;
        } else
            i++;
    }
    array[x][compt] = '\0';
    x++;
    array[x] = NULL;
    return (array);
}

char **my_str_to_all_array(char *str, char c)
{
    char **array = NULL;

    if (str == NULL)
        return (NULL);
    array = my_farraazy(array, str, c);
    array = my_arraylo(array, str, c);
    array = my_insert_arraay(array, str, c);
    return (array);
}
