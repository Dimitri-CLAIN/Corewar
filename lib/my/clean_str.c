/*
** EPITECH PROJECT, 2019
** clean my_str
** File description:
** clean up
*/

#include "../../include/my.h"

char *finish_clean(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    while (i != 0 && str[i - 1] == ' ' || str[i - 1] == '\n')
        i--;
    str[i] = '\0';
    return (str);
}

char *tab_to_space(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\t')
            str[i] = ' ';
        i++;
    }
    return (str);
}

char *first_clean(char *str)
{
    int i = 0;

    while (str[0] != '\0' && str[0] == ' ')
        str++;
    return (str);
}

char *clean_up(char *str)
{
    char *clean = malloc(sizeof(char) * (my_strlen(str) + 1));
    int n = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i + 1] == ' ')
            i++;
        else
            clean[n++] = str[i++];
    }
    clean[n] = '\0';
    return (clean);
}

char *my_clean_str(char *str)
{
    int n = 0;

    str = tab_to_space(str);
    str = first_clean(str);
    str = finish_clean(str);
    str = clean_up(str);
    return (str);
}