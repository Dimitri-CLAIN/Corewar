/*
** EPITECH PROJECT, 2019
** free_my_tab
** File description:
** free_my_tab
*/

#include <stddef.h>
#include <stdlib.h>

void free_my_tab(char **tab)
{
    int n = 0;

    while (tab[n] != NULL) {
        free(tab[n]);
        n++;
    }
}