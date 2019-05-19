/*
** EPITECH PROJECT, 2019
** prepare label indexe
** File description:
** search the indexe for the label
*/

#include "my.h"

int calcul_size_cmd(coding_style_t *glob, int pos)
{
    int n = 0;
    int l = 0;
    int size = 1;

    if (glob->code != 0)
        size++;
    while (glob->arg[n] != NULL) {
        size += glob->arg[n]->size;
        glob->arg[n]->pos_arg = pos + size;
        n++;
    }
    n--;
    return (size);
}

void int_cmd_pos(command_t *all_cmd)
{
    int n = 0;
    static int pos = 1;

    if (all_cmd->inst == NULL) {
        all_cmd->pos = pos;
        return;
    }
    pos += calcul_size_cmd(all_cmd->c_b, pos);
    all_cmd->pos = pos - calcul_size_cmd(all_cmd->c_b, pos);
}

int label_to_funct(char *label, command_t **all_cmd, int pos_label)
{
    int n = 0;
    int length = 0;

    while (all_cmd[n] != NULL) {
        //printf("cmd = [%s] name label = [%s]-> label:[%s]\n", all_cmd[n]->name, all_cmd[n]->labels.name, label);
        if (all_cmd[n]->name == NULL &&
        my_strcmp(all_cmd[n]->labels.name, label) == TRUE) {
            length = (all_cmd[n]->pos - pos_label);
            return (length);
        }
        n++;
    }
    return (length);
}

void give_indexe(int n, command_t **all_cmd)
{
    int ind = 0;
    char *str = NULL;
    int x = 0;

    while (all_cmd[n]->c_b->arg[x] != NULL) {
        if (all_cmd[n]->c_b->arg[x]->state == INDEXE) {
            if ((ind = label_to_funct(all_cmd[n]->c_b->arg[x]->arg,
            all_cmd, all_cmd[n]->pos)) != 0) {
                str = my_itoa(ind);
                all_cmd[n]->c_b->arg[x]->arg = str;
            }
        }
        x++;
    }
}

void search_label(command_t **all_cmd)
{
    int ind = 0;
    int n = 0;
    int pos_label = 0;

    while (all_cmd[n] != NULL) {
        if (all_cmd[n]->name == NULL && all_cmd[n]->state == LABEL) {
            if (all_cmd[n]->labels.cmd != NULL)
                give_indexe(0, all_cmd[n]->labels.cmd);
        } else
            give_indexe(n, all_cmd);
        n++;
    }
}