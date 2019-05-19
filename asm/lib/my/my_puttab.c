/*
** EPITECH PROJECT, 2019
** my_puttab
** File description:
** puttab
*/

#include <stddef.h>

void my_putchar(char c);
int my_putstr(char const *str);

void my_puttab(char **tab, char sep)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar(sep);
        i = i + 1;
    }
}
