/*
** EPITECH PROJECT, 2018
** my_getnr.c
** File description:
** task05
*/

#include <limits.h>
#include <stdio.h>
#include <stddef.h>

int my_getnbr(char const *str)
{
    int c = 0;
    int number = 0;
    int a = 1;

    if (str[0] == '\0' || str == NULL)
        return (0);
    while (str[c] == '-' || str[c] == '+') {
        if (str[c] == '-') {
            a = a * -1;
        }
        c = c + 1;
    }
    while (str[c] >= '0' && str[c] <= '9')
    {
        number = number * 10 + str[c] -48;
        c = c + 1;
        if (number <= (INT_MIN / 10) || number > (INT_MAX)) {
            return (0);
        }
    }
    return (number * a);
}