/*
** EPITECH PROJECT, 2019
** take
** File description:
** cmd
*/

#include "my.h"

inst_t list[] = {{"live", 4, &my_live}, {"ld", 2, &my_live}, {"st", 2, &my_live}
            , {"add", 3, &my_live}, {"sub", 3, &my_live}, {"and", 3, &my_live},
            {"or", 2, &my_live}, {"xor", 3, &my_live}, {"zjmp", 4, &my_live},
            {"ldi", 3, &my_live}, {"sti", 3, &my_live}, {"fork", 4, &my_live},
            {"lld ", 3, &my_live}, {"lldi", 4, &my_live},
            {"lfork", 5, &my_live}, {"aff", 3, &my_live}};

int check_list(char *line)
{
    char *cmp = NULL;

    cmp = cmd_name(line);
    for (int y = 0; y != 17; y++) {
        if (y == 16) {
            free(cmp);
            return (84);
        }
        if (my_strcmp(cmp, list[y].str) == TRUE) {
            free(cmp);
            return (0);
        }
    }
    free(cmp);
    return (84);
}

int bad_line_checker(char **file, asm_t *a, int name, int comment)
{
    int i = 0;

    while (file[i] != NULL) {
        file[i] = my_clean_str(file[i]);
        if (i == name || i == comment || file[i][0] == COMMENT_CHAR ||
            file[i][0] == '\0')
            i += 1;
        else if (check_list(file[i]) != 84)
            i += 1;
        else
            return (84);
    }
    return (0);
}

char **take_inst(char *cmp, char *line)
{
    int mv = my_strlen(cmp);
    char **out = NULL;

    line = my_clean_str(line);
    line = line + mv;
    line = my_clean_str(line);
    out = my_str_to_all_array(line, SEPARATOR_CHAR);
    for (int i = 0; out[i] != NULL; i++)
        out[i] = my_clean_str(out[i]);
    return (out);
}

command_t **takecmd_inst(char **file, asm_t *a)
{
    int j = 0;
    char *cmp = NULL;

    if (file == NULL)
        return (a->cmd);
    for (int i = 0; file[i]; i++) {
        cmp = cmd_name(file[i]);
        for (int y = 0; y != 16; y++) {
            my_strcmp(cmp, list[y].str) == TRUE ?
            a->cmd[j][0].inst = take_inst(cmp, file[i]), j = j + 1 : 0;
        }
        free(cmp);
    }
    return (a->cmd);
}
