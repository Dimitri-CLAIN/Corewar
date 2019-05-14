/*
** EPITECH PROJECT, 2019
** main
** File description:
** corwar main
*/

#include "my.h"

int main(int ac, char **av)
{
    int n = 0;
    char **file = NULL;

    if (av[1] == NULL)
        return (84);
    file = read_my_file(av[1]);
    while (file[n] != NULL) {
        printf("%s\n", file[n]);
        n++;
    }
    free_my_tab(file);
}
