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

void init_my_struct(asm_t *info)
{
    int n = 0;

    while (info->cmd[n] != NULL) {
        info->cmd[n]->c_b = search_coding_byte(info->cmd[n]->inst, info);
        take_int(info->cmd[n]->inst, info->cmd[n]->c_b, info->cmd[n]->name);
        int_cmd_pos(info->cmd[n]);
        n++;
    }
    info->p_s = (info->cmd[n - 1]->pos + 1);
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
    init_my_struct(info);
    search_label(info->cmd);
    create_my_bin(info, av[1]);
    ultimate_free(info, file);
}
//dernier cas a gerer !!! "live: live%1"