/*
** EPITECH PROJECT, 2019
** my itohex
** File description:
** int to hexa
*/

#include "my.h"

char *my_itohex(int nb, char *r_hex)
{
    char *hex = "0123456789ABCDEF";
    int res = 0;

    if (nb != 0) {
        res = nb % 16;
        nb = nb / 16;
        if (nb != 0)
            r_hex = my_itohex(nb, r_hex);
    }
    r_hex = add_char(r_hex ,(hex[res]));
    return (r_hex);
}
