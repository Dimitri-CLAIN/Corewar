/*
** EPITECH PROJECT, 2019
** clean_str
** File description:
** clean_str
*/

#include <unistd.h>
#include <stdlib.h>

int len_str(char *str)
{
    int len = 0;
    int i = 0;

    while (str[i] == ' ')
        i = i + 1;
    while (str[i] != '\0') {
        while (str[i] == ' ' && str[i + 1] == ' ')
            i = i + 1;
        if (str[i] == ' ' && str[i + 1] == '\0')
            return (len + 1);
        len = len + 1;
        i = i + 1;
    }
    return (len + 1);
}

char *rm_useless_space(char *str)
{
    char *out = malloc(sizeof(char) * (len_str(str)));
    int i = 0;
    int y = 0;

    while (str[i] == ' ')
        i = i + 1;
    while (str[i] != '\0') {
        while (str[i] == ' ' && str[i + 1] == ' ')
            i = i + 1;
        if (str[i] == ' ' && str[i + 1] == '\0')
            i = i + 1;
        else {
            out[y] = str[i];
            y = y + 1;
            i = i + 1;
        }
    }
    out[y] = '\0';
    return (out);
}

char *my_clean_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\t')
            str[i] = ' ';
        i = i + 1;
    }
    return (rm_useless_space(str));
}
