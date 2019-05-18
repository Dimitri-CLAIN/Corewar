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

// void init_my_struct(asm_t *info)
// {
//     int n = 0;
//     int x = 0;
//     int state = 0;

//     while (info->cmd[n] != NULL) {
//         state = check_label_or_inst(info, info->cmd[n], info->label[x]);
//         int_cmd_pos(info->cmd[n], info->label[x], state);
//         state == 1 ? x++ : n++;
//     }
//     info->p_s = (info->cmd[n - 1]->pos + 1);
// }

void init_my_struct(asm_t *info)
{
    char **arg1 = my_str_to_all_array("r1,%:live,%1", ',');
    char **arg2 = my_str_to_all_array("r1,%0,r1", ',');
    char **arg3 = my_str_to_all_array("%1", ',');
    char **arg4 = my_str_to_all_array("%:live", ',');
    command_t **cmd = malloc(sizeof(command_t *) * 5);
    labels_t label;

    cmd[0] = malloc(sizeof(command_t));
    cmd[0]->state = FALSE;
    cmd[0]->name = "sti";
    cmd[0]->inst = arg1;
    cmd[0]->c_b = search_coding_byte(cmd[0]->inst, info);
    take_int(cmd[0]->inst, cmd[0]->c_b, cmd[0]->name);
    int_cmd_pos(cmd[0]);

    cmd[1] = malloc(sizeof(command_t));
    cmd[1]->state = FALSE;
    cmd[1]->name = "and";
    cmd[1]->inst = arg2;
    cmd[1]->c_b = search_coding_byte(cmd[1]->inst, info);
    take_int(cmd[1]->inst, cmd[1]->c_b, cmd[1]->name);
    int_cmd_pos(cmd[1]);

    label.name = my_strdup("live");
    label.cmd = malloc(sizeof(command_t *) * 2);
    label.cmd[0] = malloc(sizeof(command_t));
    label.cmd[1] = NULL;
    label.cmd[0]->name = my_strdup("live");
    label.cmd[0]->inst = arg3;
    label.cmd[0]->c_b = search_coding_byte(label.cmd[0]->inst, info);
    take_int(label.cmd[0]->inst, label.cmd[0]->c_b, label.cmd[0]->name);
    int_cmd_pos(label.cmd[0]);
    cmd[2] = malloc(sizeof(command_t));
    cmd[2]->pos = label.cmd[0]->pos;
    cmd[2]->state = LABEL;
    cmd[2]->name = NULL;
    cmd[2]->labels = label;


    cmd[3] = malloc(sizeof(command_t));
    cmd[3]->state = FALSE;
    cmd[3]->name = "zjmp";
    cmd[3]->inst = arg4;
    cmd[3]->c_b = search_coding_byte(cmd[3]->inst, info);
    take_int(cmd[3]->inst, cmd[3]->c_b, cmd[3]->name);
    int_cmd_pos(cmd[3]);
    cmd[4] = NULL;
    info->cmd = cmd;

    info->p_s = (info->cmd[3]->pos + 2);
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