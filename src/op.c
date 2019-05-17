/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Tue Mar 22 16:44:20 2011 Astek
*/

#include "op.h"
#include "enum.h"

op_t op_tab[] = {
    {"live", 1, {{T_DIR, 0}}, 1, 10, "alive"},
    {"ld", 2, {{T_DIR, T_IND, 0}, {T_REG, 0}}, 2, 5, "load"},
    {"st", 2, {{T_REG, 0}, {T_IND, T_REG, 0}}, 3, 5, "store"},
    {"add", 3, {{T_REG, 0}, {T_REG, 0}, {T_REG, 0}}, 4, 10, "addition"},
    {"sub", 3, {{T_REG, 0}, {T_REG, 0}, {T_REG, 0}}, 5, 10, "soustraction"},
    {"and", 3, {{T_REG, T_DIR, T_IND, 0}, {T_REG, T_IND, T_DIR, 0}, {T_REG, 0}}, 6, 6,
    "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {{T_REG, T_IND, T_DIR, 0}, {T_REG, T_IND, T_DIR, 0}, {T_REG, 0}}, 7, 6,
    "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {{T_REG, T_IND, T_DIR, 0}, {T_REG, T_IND, T_DIR, 0}, {T_REG, 0}}, 8, 6,
    "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {{INDEXE, 0}}, 9, 20, "jump if zero"},
    {"ldi", 3, {{INDEXE, 0}, {INDEXE, 0}, {T_REG, 0}}, 10, 25,
    "load index"},
    {"sti", 3, {{T_REG, 0}, {T_REG, INDEXE, 0}, {INDEXE, T_REG, 0}}, 11, 25,
    "store index"},
    {"fork", 1, {{INDEXE, 0}}, 12, 800, "fork"},
    {"lld", 2, {{T_DIR, T_IND, 0}, {T_REG, 0}}, 13, 10, "long load"},
    {"lldi", 3, {{INDEXE, 0}, {INDEXE, 0}, {T_REG, 0}}, 14, 50,
    "long load index"},
    {"lfork", 1, {{INDEXE, 0}}, 15, 1000, "long fork"},
    {"aff", 1, {{T_REG, 0}}, 16, 2, "aff"},
    {0, 0, {{0}}, 0, 0, 0}
};
