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
    info->header.prog_size = big_to_little_endian(23, DIR_SIZE);
    complet_str(n, info->comment, info->header.comment);
}

void write_header(asm_t *info, int fd)
{
    prepare_header(info);
    write(fd, &info->header, sizeof(info->header));
}

int create_my_bin(asm_t *info)
{
    char *name = my_strcat(info->name, ".cor");
    int fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0664);

    write_header(info, fd);
    //creat_cmd(info, fd);
//    write_commande(info, fd);
    return (0);
}
