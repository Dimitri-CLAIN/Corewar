/*
** EPITECH PROJECT, 2019
** create my bin
** File description:
** create my bin
*/

#include "my.h"

int create_my_bin(/*struct*/)
{
    char *name = my_strcat(/*struct*/.name, ".cor");
    int fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0664);

    write(fd, &/*struct*/.cmd, sizeof(/*struct*/.cmd));
}
