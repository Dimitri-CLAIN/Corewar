/*
** EPITECH PROJECT, 2019
** my_memset
** File description:
** MY_memset
*/

#include <stdlib.h>

char *my_memset(char *str, int size, char c)
{
    int n = 0;

    while (n != size) {
        str[n] = c;
        n++;
    }
    return (str);
}