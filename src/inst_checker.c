/*
** EPITECH PROJECT, 2019
** inst
** File description:
** checker
*/

#include "my.h"

inst_t lst[] = {{"live", 4, &my_live}, {"ld", 2, &my_live}, {"st", 2, &my_live}
            , {"add", 3, &my_live}, {"sub", 3, &my_live}, {"and", 3, &my_live},
            {"or", 2, &my_live}, {"xor", 3, &my_live}, {"zjmp", 4, &my_live},
            {"ldi", 3, &my_live}, {"sti", 3, &my_live}, {"fork", 4, &my_live},
            {"lld ", 3, &my_live}, {"lldi", 4, &my_live},
            {"lfork", 5, &my_live}, {"aff", 3, &my_live}};

char *label_name(char *file)
{
    int len = 0;
    int i = 0;
    char *out = NULL;

    while (file[len] != LABEL_CHAR && file[len] != '\0')
        len++;
    out = malloc(sizeof(char) * (len + 1));
    while (i != len) {
        out[i] = file[i];
        i = i + 1;
    }
    out[i] = '\0';
    return (out);
}

char *inst_name(char *file)
{
    int len = 0;
    int i = 0;
    char *out = NULL;

    while (file[len] != LABEL_CHAR && file[len] != '\0')
        len++;
    out = malloc(sizeof(char) * (len + 1));
    while (i != len) {
        out[i] = file[i];
        i = i + 1;
    }
    out[i] = '\0';
    return (out);
}

command_t *set_inst(char *line, asm_t *info)
{
    command_t *out = malloc(sizeof(command_t));

    out->state = FALSE;
    out->name = cmd_name(line);
    if (my_strlen(out->name) >= my_strlen(line))
        out->inst = NULL;
    line = line + my_strlen(out->name);
    line = my_clean_str(line);
    if (line[0] == '\0')
        out->inst = NULL;
    out->inst = my_str_to_all_array(line, SEPARATOR_CHAR);
    for (int i = 0; out->inst != NULL && out->inst[i] != NULL; i++)
        out->inst[i] = my_clean_str(out->inst[i]);
    out->pos = 0;
    out->c_b = search_coding_byte(out->inst, info, out->name);
    take_int(out->inst, out->c_b, out->name);
    int_cmd_pos(out);
    return (out);
}

command_t *set_label(char *line, asm_t *info)
{
    command_t *out = malloc(sizeof(command_t));

    out->state = LABEL;
    out->name = NULL;
    out->inst = NULL;
    out->labels.name = label_name(line);
    if ((my_strlen(out->labels.name) + 1) >= my_strlen(line))
        out->labels.cmd = NULL;
    line = line + (my_strlen(out->labels.name) + 1);
    line = my_clean_str(line);
    if (line[0] == '\0') {
        out->labels.cmd = NULL;
        int_cmd_pos(out);
        return (out);
    }
    out->labels.cmd = malloc(sizeof(command_t *) * 2);
    out->labels.cmd[0] = malloc(sizeof(command_t));
    out->labels.cmd[0] = set_inst(line, info);
    out->labels.cmd[1] = NULL;
    out->pos = out->labels.cmd[0]->pos;
    return (out);
}

void sv_cmd(char **file, asm_t *a, int name, int comment)
{
    char *cmp = NULL;
    int j = 0;

    for (int i = 0; file[i] != NULL; i++) {
        cmp = my_clean_str(file[i]);
        if (cmp[0] != COMMENT_CHAR && check_label(cmp) == TRUE) {
            a->cmd[j] = set_label(cmp, a);
            j = j + 1;
        }
        else if (cmp[0] != '\0' &&
            cmp[0] != COMMENT_CHAR && check_inst(cmp) == TRUE) {
                a->cmd[j] = set_inst(cmp, a);
                j = j + 1;
            }
        free(cmp);
    }
    a->cmd[j] = NULL;
    a->p_s = (a->cmd[j - 1]->pos + 2);
}