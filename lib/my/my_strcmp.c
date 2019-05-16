/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** my_strncmp
*/

#include "../../include/my.h"

int check_len(char *s1, char *s2)
{
    int len_one = 0;
    int len_two = 0;

    if (s1 != NULL)
        len_one = my_strlen(s1);
    if (s2 != NULL)
        len_two = my_strlen(s2);
    if (len_one != len_two)
        return (84);
}

int my_strcmp(char *s1, char *s2)
{
    int n = 0;

    if (check_len(s1, s2) == 84)
        return (FALSE);
    while (s1[n] != '\0' && s2[n] != '\0') {
        if (s1[n] != s2[n])
            return (FALSE);
        n++;
    }
    return (TRUE);
}

int checkn_len(char *s1, char *s2, int nb)
{
    int len_one = 0;
    int len_two = 0;

    if (s1 != NULL)
        len_one = my_strlen(s1);
    if (s2 != NULL)
        len_two = my_strlen(s2);
    if (len_one >= nb && len_two >= nb)
        return (0);
    if (len_one != len_two)
        return (84);
}

int my_strncmp(char *s1, char *s2, int nb)
{
    int n = 0;

    if (checkn_len(s1, s2, nb) != 0)
        return (84);
    while (s1[n] != '\0' && s2[n] != '\0' && n != nb) {
        if (s1[n] != s2[n])
            return (-1);
        n = n + 1;
    }
    return (0);
}