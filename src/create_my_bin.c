/*
** EPITECH PROJECT, 2019
** create my bin
** File description:
** create my bin
*/

#include "my.h"
#include "op.h"

char *complet_str(int n, char *str, char *head)
{
    int x = 0;

    while (str[x] != '\0') {
        head[n] = str[x];
        x++;
        n++;
    }
    return (head);
}

void prepare_header(asm_t *info)
{
    int n = 0;

    info->header.magic = big_to_little_endian(COREWAR_EXEC_MAGIC, DIR_SIZE);
    complet_str(n, info->name, info->header.name);
    info->header.prog_size = big_to_little_endian(info->p_s, DIR_SIZE);
    complet_str(n, info->comment, info->header.comment);
}

void write_header(asm_t *info, int fd)
{
    prepare_header(info);
    write(fd, &info->header, sizeof(info->header));
}

void write_cmd(command_t *cmd, int fd)
{
    int n = 0;
    unsigned int arg = 0;

    while (my_strcmp(op_tab[n].mnemonique, cmd->name) != TRUE)
        n++;
    write(fd, &op_tab[n].code, 1);
    if (cmd->c_b->code != 0)
        write(fd, &cmd->c_b->code, 1);
    n = 0;
    while (cmd->c_b->arg[n] != NULL) {
        arg = my_getnbr(cmd->c_b->arg[n]->arg);
        if (cmd->c_b->arg[n]->size != 1)
            arg = big_to_little_endian(arg, cmd->c_b->arg[n]->size);
        write(fd, &arg, cmd->c_b->arg[n]->size);
        n++;
    }
}

int create_my_bin(asm_t *info, char *name)
{
    char *nm = my_strcat(give_name(name), ".cor");
    int fd = open(nm, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    int n = 0;
    int x = 0;

    write_header(info, fd);
    while (info->cmd[n] != NULL) {
        if (info->cmd[n]->state != LABEL)
            write_cmd(info->cmd[n], fd);
        else if (info->cmd[n]->labels.cmd != NULL) {
            write_cmd(info->cmd[n]->labels.cmd[x], fd);
            x++;
        }
        n++;
    }
    return (0);
}
