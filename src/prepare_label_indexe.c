/*
** EPITECH PROJECT, 2019
** prepare label indexe
** File description:
** search the indexe for the label
*/

#include "my.h"

int calcul_size_cmd(coding_style_t *glob)
{
    int n = 0;
    static int size = 1;

    if (glob->code != 0)
        size++;
    while (glob->arg[n] != NULL) {
        size += glob->arg[n]->size;
        glob->arg[n]->pos_arg = size;
        n++;
    }
    n--;
    size++;
    return (size);
}

void int_cmd_pos(command_t *all_cmd)
{
    int n = 0;
    int pos = 0;

    all_cmd->pos = calcul_size_cmd(all_cmd->c_b);
}

int label_to_funct(char *label, command_t **all_cmd, int pos_label)
{
    int n = 0;
    int length = 0;

    while (all_cmd[n] != NULL) {
        if (my_strcmp(all_cmd[n]->name, label) == TRUE) {
            length = (all_cmd[n]->pos - pos_label) + 1;
            return (length);
        }
        n++;
    }
    return (length);
}

void give_indexe(int n, command_t **all_cmd)
{
    int ind = 0;
    int x = 0;

    while (all_cmd[n]->c_b->arg[x] != NULL) {
        if (all_cmd[n]->c_b->arg[x] != NULL &&
        all_cmd[n]->c_b->arg[x]->state == INDEXE) {
            if ((ind = label_to_funct(all_cmd[n]->c_b->arg[x]->arg,
            all_cmd, all_cmd[n]->c_b->arg[x]->pos_arg)) != 0)
                all_cmd[n]->c_b->arg[x]->arg = my_itoa(ind);
        }
        x++;
    }
}

void search_label(command_t **all_cmd)
{
    int ind = 0;
    int n = 0;
    int x = 0;
    int pos_label = 0;

    while (all_cmd[n] != NULL) {
        give_indexe(n, all_cmd);
        n++;
    }
}