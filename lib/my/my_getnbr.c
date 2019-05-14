/*
** EPITECH PROJECT, 2018
** my_getnr.c
** File description:
** task05
*/

#include <limits.h>
#include <stdio.h>

int my_check_c(char s)
{
    char *flag = "-+0123456789=\n";
    int n = 0;

    while (flag[n] != '\0') {
        if (flag[n] == s)
            return (1);
        n++;
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int x = 0;
    int nb = 0;

    while (str[x] != '\0') {
        if (my_check_c(str[x]) == 0)
            return (-1);
        x++;
    }
    for (x = 0; str[x] >= '0' && str[x] <= '9'; x++) {
        nb = nb * 10 + str[x] - 48;
        if (nb <= (INT_MIN / 10) || nb > (INT_MAX))
            return (-1);
    }
    return (nb);
}
