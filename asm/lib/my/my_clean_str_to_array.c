/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** array_to_double_array
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

char **mysecond_ar(char **array, char *str, char c)
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

char **my_first_ar(char **array, char *str, char c)
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

char **my_tres_ar(char **array, char *str, char c)
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

char **my_clean_str_to_array(char *str, char c)
{
    char **array = NULL;
    char *clean = NULL;

    if (str == NULL)
        return (NULL);
    str = my_clean_str(str);
    clean = my_strdup(str);
    array = my_first_ar(array, clean, c);
    array = mysecond_ar(array, clean, c);
    array = my_tres_ar(array, clean, c);
    return (array);
}
