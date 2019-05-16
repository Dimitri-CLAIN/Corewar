/*
** EPITECH PROJECT, 2019
** take
** File description:
** cmd
*/

#include "my.h"

inst_t list[] = {{"live", 4}, {"ld", 2}, {"st", 2}, {"add", 3}, {"sub", 3},
            {"and", 3}, {"or", 2}, {"xor", 3}, {"zjmp", 4} , {"ldi", 3},
            {"sti", 3}, {"fork", 4}, {"lld ", 3}, {"lldi", 4},
            {"lfork", 5}, {"aff", 3}};

char **take_inst(char *cmp, char *line)
{
    int mv = my_strlen(cmp);
    char **out = NULL;

    line = my_clean_str(line);
    line = line + mv;
    line = my_clean_str(line);
    out = my_str_to_all_array(line, SEPARATOR_CHAR);
    for (int i = 0 ; out[i] != NULL ; i++)
        out[i] = my_clean_str(out[i]);
    return (out);
}

struct comment_t *takecmd_inst(char **file, asm_t *a)
{
    int j = 0;
    char *cmp = NULL;

    if (file == NULL)
        return (a->cmd);
    for (int i = 0 ; file[i] ; i++) {
        cmp = cmd_name(file[i]);
        for (int y = 0 ; y != 16 ; y++) {
            my_strcmp(cmp, list[y].str) == TRUE ?
            a->cmd[j].inst = take_inst(cmp, file[i]), j = j + 1 : 0;
        }
        free(cmp);
    }
    return (a->cmd);
}