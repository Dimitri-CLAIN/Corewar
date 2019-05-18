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

char *cmd_name(char *file)
{
    int len = 0;
    int i = 0;
    char *out = NULL;

    while (file[len] >= 'a' && file[len] <= 'z')
        len++;
    out = malloc(sizeof(char) * (len + 1));
    while (i != len) {
        out[i] = file[i];
        i = i + 1;
    }
    out[i] = '\0';
    return (out);
}

int check_val_pos(int pos, int name, int comment)
{
    if (pos > name && pos > comment)
        return (0);
    return (84);
}
/*
int cmd_len(char **file, asm_t *a)
{
    int len = 0;
    char *cmp = NULL;

    if (file == NULL)
        return (84);
    for (int i = 0 ; file[i] ; i++) {
        cmp = cmd_name(file[i]);
        for (int y = 0 ; y != 16 ; y++) {
            my_strcmp(cmp, test[y].str) == TRUE ? len = len + 1 : 0;
        }
        free(cmp);
    }
    return (len);
}
*/
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
/*
int get_inst(char **file, asm_t *a, int name, int comment)
{
    a->cmd_nb = cmd_len(file, a);
    a->cmd = malloc(sizeof(command_t *) * (a->cmd_nb + 1));
    for (int i = 0; i != a->cmd_nb ; i++)
        a->cmd[i] = malloc(sizeof(command_t));
    a->cmd[a->cmd_nb] = NULL;
    a->cmd = takecmd_name(file, a);
    a->cmd = takecmd_inst(file, a);
}*/

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

    for (int i = 0; file[i] != NULL; i++) {
        cmp = my_clean_str(file[i]);
        if (cmp[0] != COMMENT_CHAR && check_label(cmp) == TRUE)
            len++;
        else if (cmp[0] != '\0' && 
            cmp[0] != COMMENT_CHAR && check_inst(cmp) == TRUE)
            len++;
        free(cmp);
    }
    return (len);
}

int get_cmd(char **file, asm_t *a, int name, int comment)
{
    int nb = get_cmd_nb(file, a, name, comment);

    if (nb == 0) {
        a->cmd = NULL;
        return (0);
    }
    a->cmd = malloc(sizeof(command_t *) * (nb + 1));
    sv_cmd(file, a, name, comment);
    return (0);
}