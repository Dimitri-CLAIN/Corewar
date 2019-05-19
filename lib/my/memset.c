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
    char *mem = malloc(sizeof(char) * (size + 1));

    while (n != size) {
        mem[n] = c;
        n++;
    }
    return (mem);
}