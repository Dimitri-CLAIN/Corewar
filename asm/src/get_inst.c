/*
** EPITECH PROJECT, 2019
** get
** File description:
** inst
*/

#include "my.h"

inst_t test[] = {{"live", 4, &my_live}, {"ld", 2, &my_live}, {"st", 2, &my_live}
            , {"add", 3, &my_live}, {"sub", 3, &my_live}, {"and", 3, &my_live},
            {"or", 2, &my_live}, {"xor", 3, &my_live}, {"zjmp", 4, &my_live},
            {"ldi", 3, &my_live}, {"sti", 3, &my_live}, {"fork", 4, &my_live},
            {"lld", 3, &my_live}, {"lldi", 4, &my_live}, {"lfork", 5, &my_live},
            {"aff", 3, &my_live}};

command_t **takecmd_name(char **file, asm_t *a)
{
    int j = 0;
    char *cmp = NULL;

    if (file == NULL)
        return (a->cmd);
    for (int i = 0 ; file[i] ; i++) {
        cmp = cmd_name(file[i]);
        for (int y = 0 ; y != 16 ; y++) {
            my_strcmp(cmp, test[y].str) == TRUE ?
            a->cmd[j][0].name = my_strcpy(cmp), j = j + 1 : 0;
        }
        free(cmp);
    }
    return (a->cmd);
}

int check_label(char *str)
{
    int y = 0;

    for (y = 0; str[y] != '\0' && str[y] != SEPARATOR_CHAR &&
    str[y] != LABEL_CHAR && str[y] != DIRECT_CHAR; y++);
    if (str[y] == LABEL_CHAR)
        return (TRUE);
    else
        return (FALSE);
}

int check_inst(char *str)
{
    char *cmp = NULL;

    cmp = cmd_name(str);
    for (int y = 0; y != 16; y++) {
        if (my_strcmp(cmp, test[y].str) == TRUE) {
            free(cmp);
            return (TRUE);
        }
    }
    free(cmp);
    return (FALSE);
}

int get_cmd_nb(char **file, asm_t *a, int name, int comment)
{
    char *cmp = NULL;
    int len = 0;
    int error = 0;

    for (int i = 0; file[i] != NULL; i++) {
        cmp = my_clean_str(file[i]);
        if (cmp[0] != '\0' &&
            cmp[0] != COMMENT_CHAR && check_label(cmp) == TRUE)
            i < name || i < comment ? error = 84 : len++;
        else if (cmp[0] != '\0' &&
            cmp[0] != COMMENT_CHAR && check_inst(cmp) == TRUE)
            i < name || i < comment ? error = 84 : len++;
        else if (cmp[0] != '\0' &&
            cmp[0] != COMMENT_CHAR && i != name && i != comment)
            return (-1);
        free(cmp);
        if (error == 84)
            return (-1);
    }
    return (len);
}

int get_cmd(char **file, asm_t *a, int name, int comment)
{
    int nb = get_cmd_nb(file, a, name, comment);

    if (nb == -1)
        return (84);
    if (nb == 0) {
        a->cmd = NULL;
        return (0);
    }
    a->cmd = malloc(sizeof(command_t *) * (nb + 1));
    sv_cmd(file, a, name, comment);
    return (0);
}