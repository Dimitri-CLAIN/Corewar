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
    int n = 0;
    char **file = NULL;
    asm_t *info = malloc(sizeof(asm_t));

    if (av[1] == NULL) {
        free(info);
        return (84);
    }
    file = read_my_file(av[1]);
    if (file == NULL)
        return (84);
    if (check_file(file, info) == 84) {
        ultimate_free(info, file);
        return (84);
    }
    while (info->cmd[n] != NULL) {
        info->cmd[n]->c_b = search_coding_byte(info->cmd[n]->inst, info);
        take_int(info->cmd[n]->inst, info->cmd[n]->c_b, info->cmd[n]->name);
        n++;
    }
    create_my_bin(info, av[1]);
    ultimate_free(info, file);
}
