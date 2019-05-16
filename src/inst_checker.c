/*
** EPITECH PROJECT, 2019
** inst
** File description:
** checker
*/

#include "my.h"

inst *list_create(void)
{
    inst list[] = {{"live", 4}, {"ld", 2}, {"st", 2}, {"add", 3}, {"sub", 3},
                    {"and", 3}, {"or", 2}, {"xor", 3}, {"zjmp", 4} , {"ldi", 3},
                    {"sdi", 3}, {"fork", 4}, {"lld", 3}, {"lldi", 4},
                    {"lfork", 5}, {"aff", 3}};
    return (list);
}

int  inst_checker(asm_t *a)
{
    inst *list = list_create();

    for (int z = 0 ; a->inst[z] ; z++) {
        for (int y = 0 ; y != 17 ; y++) {
            if (y == 16)
                return (84);
            if (my_strncmp(a->inst[z], list[y].str, list[y].len) == 0);
                return (0);
        }
    }
    return (0);
}