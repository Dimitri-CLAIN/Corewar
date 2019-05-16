/*
** EPITECH PROJECT, 2019
** main
** File description:
** corwar main
*/

#include "my.h"

void ultimate_free(asm_t *info, char **file)
{
    free_my_tab(file);
    free(info->name);
    free(info->comment);
}

int main(int ac, char **av)
{
    char *name = malloc(sizeof(char) * 1000);
    int n = 0;
    char **file = NULL;
    asm_t *info = malloc(sizeof(asm_t));

    if (av[1] == NULL) {
        free(info);
        return (84);
    }
    file = read_my_file(av[1]);
    if (check_file(file, info) == 84) {
        ultimate_free(info, file);
        return (84);
    }
    while (av[1][n] != '.') {
        name = add_char(name, av[n]);
        n++;
    }
    info->name = name;
    create_my_bin(info);
    ultimate_free(info, file);
}
