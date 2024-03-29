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
    for (int y = 0; line[y] != '\0' && line[y] != 34; y++, len++);
    name = malloc(sizeof(char) * (len + 1));
    for (int z = 0; line[z] != '\0' && line[z] != 34; z++) {
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
        file[i] = my_clean_str(file[i]);
        if (my_strncmp(file[i], NAME_CMD_STRING,
            my_strlen(NAME_CMD_STRING)) == 0 &&
            file[i][5] == ' ') {
            last = i;
            take_name(file[i], a);
            nb = nb + 1;
        }
        i = i + 1;
    }
    if (nb != 1 || a->name == NULL || my_strlen(a->name) > PROG_NAME_LENGTH)
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
    for (int y = 0; line[y] != '\0' && line[y] != 34; y++, len++);
    comment = malloc(sizeof(char) * (len + 1));
    for (int z = 0; line[z] != '\0' && line[z] != 34; z++) {
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
        file[i] = my_clean_str(file[i]);
        if (my_strncmp(file[i], COMMENT_CMD_STRING,
            my_strlen(COMMENT_CMD_STRING)) == 0 && file[i][8] == ' ') {
            take_comment(file[i], a);
            last = i;
            nb = nb + 1;
        }
        i = i + 1;
    }
    if (nb != 1 || a->comment == NULL || my_strlen(a->comment) > COMMENT_LENGTH)
        return (84);
    return (last);
}

int check_file(char **file, asm_t *a)
{
    int name = get_name(file, a);
    int comment = get_comment(file, a);
    int labels = get_cmd(file, a, name, comment);
    int inst = 0;

    if (name == 84 || comment == 84 || comment < name || labels == 84)
        return (84);
    for (int i = 0; a->cmd != NULL && a->cmd[i] != NULL; i++) {
        if (a->cmd[i][0].state == LABEL && val_label(a->cmd[i][0], a) == 84)
            return (84);
        if (a->cmd[i][0].state == FALSE && val_inst(a->cmd[i][0], a) == 84)
            return (84);
    }
    return (0);
}
