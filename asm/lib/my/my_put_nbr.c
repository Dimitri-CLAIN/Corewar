/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** nbr
*/

#include <unistd.h>
#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int div = 1;
    int result = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    while ((nb / div) >= 10)
        div = div * 10;
    while (div > 0) {
        result = (nb/div) % 10;
        my_putchar(result + 48);
        div = div / 10;
    }
    return (0);
}
