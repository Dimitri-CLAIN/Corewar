/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** my_strncmp
*/

#include "../../include/my.h"

int my_strcmp(char *s1, char *s2)
{
    int n = 0;
    int one = my_strlen(s1);
    int two = my_strlen(s2);

    if (one != two)
        return (FALSE);
    while (s1[n] != '\0' && s2[n] != '\0') {
        if (s1[n] != s2[n])
            return (FALSE);
        n++;
    }
    return (TRUE);
}
