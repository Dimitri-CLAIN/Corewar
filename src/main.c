/*
** EPITECH PROJECT, 2019
** main
** File description:
** corwar main
*/

#include "my.h"

int main(int ac, char **av)
{
    char **file = NULL;
    asm_t a;

    if (av[1] == NULL)
        return (84);
    file = read_my_file(av[1]);
    if (check_file(file, &a) == 84)
        return (84);
    free_my_tab(file);
    free(a.name);
    free(a.comment);
}
