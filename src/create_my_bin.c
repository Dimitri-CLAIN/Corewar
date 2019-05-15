/*
** EPITECH PROJECT, 2019
** create my bin
** File description:
** create my bin
*/

#include "my.h"
#include "op.h"

char *prepare_malloc(int size, char *str)
{
    int n = 0;

    str = malloc(sizeof(char) *(size + 1));
    str[size] = '\0';
    while (n != size) {
        str[n] = 0;
        n++;
    }
    return (str);
}

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
    int n = 1;
    int x = 0;

    info->header.name = prepare_malloc(PROG_NAME_LENGTH, info->header.name);
    info->header.name[n] = 234;
    info->header.name[n + 1] = 131;
    info->header.name[n + 2] = 243;
    n += 3;
    info->header.name = complet_str(n, info->name, info->header.name);
    n = 11;
    info->header.comment = prepare_malloc(COMMENT_LENGTH, info->header.comment);
    info->header.comment[n] = 23;
    n++;
    info->header.comment = complet_str(n, info->comment, info->header.comment);
}

void write_header(asm_t *info, int fd)
{
    prepare_header(info);
    write(fd, info->header.name, PROG_NAME_LENGTH);
    write(fd, info->header.comment, COMMENT_LENGTH);
}

int create_my_bin(asm_t *info)
{
    char *name = my_strcat(info->name, ".cor");
    int fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0664);

    write_header(info, fd);
    return (0);
}
