/*
** EPITECH PROJECT, 2019
** get
** File description:
** inst
*/

#include "my.h"

int get_inst_nb(char **file, int name, int comment)
{
    int i = 0;
    int nb = 0;

    while (file[i] != NULL) {
        if (file[i][0] != '\0' && i != name && i != comment &&
            file[i][0] != '#' && file[i][my_strlen(file[i]) - 1] != ':') {
            nb = nb + 1;
        }
        i = i + 1;
    }
    return (nb);
}

int check_val_pos(int pos, int name, int comment)
{
    if (pos > name && pos > comment)
        return (0);
    return (84);
}

int get_inst(char **file, asm_t *a, int name, int comment)
{
    int y = 0;
    int pos = 0;
    int nb = get_inst_nb(file, name, comment);

    a->inst = NULL;
    if (nb == 0)
        return (0);
    a->inst = malloc(sizeof(char *) * (get_inst_nb(file, name, comment) + 1));
    for (int i = 0 ; file[i] != NULL ; i++) {
        file[i] = my_clean_str(file[i]);
        if (file[i][0] != '\0' && i != comment && i != name &&
            file[i][0] != '#' && file[i][my_strlen(file[i]) - 1] != ':') {
            a->inst[y] = file[i];
            pos = check_val_pos(i, name, comment);
            y = y + 1;
        }
        if (pos != 0)
            return (84);
    }
    a->inst[y] = NULL;
    return (0);
}