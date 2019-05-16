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

void init_my_commande(asm_t **info)
{
    char **inst1 = my_str_to_all_array("r1,%:live,%1", ',');
    char **inst2 = my_str_to_all_array("r1,%0,r1", ',');
    char **inst3 = my_str_to_all_array("%1", ',');
    command_t **cmd = malloc(sizeof(command_t *) * 4);

    cmd[0] = malloc(sizeof(command_t));
    cmd[1] = malloc(sizeof(command_t));
    cmd[2] = malloc(sizeof(command_t));
    cmd[3] = NULL;
    cmd[0]->name = "sti";
    cmd[0]->inst = inst1;
    cmd[0]->c_b = search_coding_byte(cmd[0]->inst, *info);
    cmd[1]->name = "and";
    cmd[1]->inst = inst2;
    cmd[1]->c_b = search_coding_byte(cmd[1]->inst, *info);
    cmd[2]->name = "live";
    cmd[2]->inst = inst3;
    cmd[2]->c_b = search_coding_byte(cmd[2]->inst, *info);
    take_int(inst1, cmd[0]->c_b);
    take_int(inst2, cmd[1]->c_b);
    take_int(inst3, cmd[2]->c_b);
    (*info)->cmd = cmd;
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
        take_int(info->cmd[n]->inst, info->cmd[n]->c_b);
        n++;
    }
    create_my_bin(info, av[1]);
    ultimate_free(info, file);
}
