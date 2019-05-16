/*
** EPITECH PROJECT, 2019
** check
** File description:
** file
*/

#include "my.h"

void take_name(char *line, asm_t *a)
{
    char *name = NULL;
    int len = 0;

    while (line[0] != 34 && line[0] != '\0')
        line++;
    if (line[0] == '\0')
        return;
    line++;
    for (int y = 0 ; line[y] != '\0' && line[y] != 34 ; y++, len++);
    name = malloc(sizeof(char) * (len + 1));
    for (int z = 0; line[z] != '\0' && line[z] != 34 ; z++) {
        name[z] = line[z];
        name[z + 1] = '\0';
    }
    a->name = name;
}

int get_name(char **file, asm_t *a)
{
    int i = 0;
    int nb = 0;
    int last = 0;

    a->name = NULL;
    while (file[i] != NULL) {
        if (strncmp(file[i], ".name", 5) == 0) {
            last = i;
            take_name(file[i], a);
            nb = nb + 1;
        }
        i = i + 1;
    }
    if (nb != 1 || a->name == NULL)
        return (84);
    return (last);
}

void take_comment(char *line, asm_t *a)
{
    char *comment = NULL;
    int len = 0;

    while (line[0] != 34 && line[0] != '\0')
        line++;
    if (line[0] == '\0')
        return;
    line++;
    for (int y = 0 ; line[y] != '\0' && line[y] != 34 ; y++, len++);
    comment = malloc(sizeof(char) * (len + 1));
    for (int z = 0; line[z] != '\0' && line[z] != 34 ; z++) {
        comment[z] = line[z];
        comment[z + 1] = '\0';
    }
    a->comment = comment;
}

int get_comment(char **file, asm_t *a)
{
    int i = 0;
    int nb = 0;
    int last = 0;

    a->comment = NULL;
    while (file[i] != NULL) {
        if (strncmp(file[i], ".comment", 8) == 0) {
            take_comment(file[i], a);
            last = i;
            nb = nb + 1;
        }
        i = i + 1;
    }
    if (nb != 1 || a->comment == NULL)
        return (84);
    return (last);
}

int check_file(char **file, asm_t *a)
{
    int name = get_name(file, a);
    int comment = get_comment(file, a);
    int inst = 0;

    if (name == 84 || comment == 84 || comment < name)
        return (84);
    inst = get_inst(file, a, name, comment);
    if (inst == 84)
        return (84);
    return (0);
}