/*
** EPITECH PROJECT, 2019
** check_arg
** File description:
** check_arg
*/

#include "my.h"

char *commande(char *cmd, int n)
{
    // verifier si c'est une commande ou un label, si c'est un label, on doit
    // commencer a partire du suivant;
    // faire une structure label, a chaque vue d'un label, on ecrie dans une struct,
    // dans la structure on a le label(char *), position(int), la commande quelle fait
}

char *take_arg(char *cmd, int n)
{
    char *arg = NULL;

    arg = my_strdup("");
    while (cmd[n] != '\0') {
        if (cmd[n] != LABEL_CHAR)
            arg = add_char(arg, cmd[n]);
        n++;
    }
    return (arg);
}