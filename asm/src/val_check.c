/*
** EPITECH PROJECT, 2019
** val
** File description:
** check
*/

#include "my.h"

int label_use_ck(char *line, asm_t *info, int error)
{
    int stop = -1;

    for (; line[0] != '\0' && line[0] != LABEL_CHAR; line++);
    if (line[0] == '\0')
        return (error);
    line++;
    line = my_clean_str(line);
    if (line[0] == '\0')
        return (error);
    for (int i = 0; info->cmd != NULL && info->cmd[i] != NULL; i++) {
        if (info->cmd[i][0].state == LABEL &&
            my_strcmp(line, info->cmd[i][0].labels.name) == TRUE)
            return (error);
    }
    return (84);
}

int whatis_myflag(char *cmd, char *cmd_name, int pos)
{
    int flag = 0;

    if (cmd == NULL && cmd[0] == '\0' || cmd_name == NULL)
        return (84);
    if (cmd[0] == DIRECT_CHAR) {
        flag = T_DIR;
    } else if (cmd[0] == 'r') {
        flag = T_REG;
    } else {
        flag = T_IND;
    }
    flag = check_flag(cmd, cmd_name, flag, pos);
    return (flag);
}

int type_checker(args_type_t arg, char *str, char *cmd_name, int pos)
{
    int flag = whatis_myflag(str, cmd_name, pos);

    if (flag == 84)
        return (84);
    for (int i = 0; arg.type_arg[i] != 0; i++) {
        if (flag == arg.type_arg[i])
            return (0);
    }
    return (84);
}

int val_inst(command_t cmd, asm_t *info)
{
    int i = 0;
    int error = 0;

    for (i = 0; i != 17 &&
        my_strcmp(cmd.name, op_tab[i].mnemonique) != TRUE; i++);
    if (i == 17)
        return (84);
    if (my_tablen(cmd.inst) != op_tab[i].nbr_args ||
        op_tab[i].nbr_args > MAX_ARGS_NUMBER)
        return (84);
    for (int y = 0; y != op_tab[i].nbr_args && error != 84; y++) {
        error = type_checker(op_tab[i].type[y], cmd.inst[y], cmd.name, y);
        error = label_use_ck(cmd.inst[y], info, error);
    }
    if (error == 84)
        return (84);
    return (0);
}

int val_label(command_t cmd, asm_t *info)
{
    if (cmd.labels.name == NULL)
        return (84);
    for (int i = 0; cmd.labels.name[i] != '\0'; i++)
            if (check_label_char(cmd.labels.name[i]) == 84)
                return (84);
    if (cmd.labels.cmd != NULL)
        return (val_inst(cmd.labels.cmd[0][0], info));
    return (0);
}