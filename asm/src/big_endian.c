/*
** EPITECH PROJECT, 2019
** big endian
** File description:
** check big or little endian
*/

#include "my.h"

int big_to_little_endian(int nb, int size)
{
    unsigned int x = 1;
    char *big = (char*)&x;

    if (*big) {
        if (size == 4)
            return (
                ((nb >> 24) & 0x0000000ff) |
                ((nb >> 8) & 0x0000ff00) |
                ((nb << 8) & 0x000ff0000) |
                ((nb << 24) & 0xff000000));
        else
            return (nb << 8) | ((nb >> 8) & 0xff);
    } else
        return (nb);
}
