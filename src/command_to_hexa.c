/*
** EPITECH PROJECT, 2019
** commande to hexa
** File description:
** commande to hexa
*/

#include "my.h"
#include "op.h"

int detect_my_cmd(char *cmd)
{
    if (cmd[0] == 'r')
        return (REGISTER);
    if (cmd[0] == '%')
        return (DIRECT);
    if (my_getnbr(cmd) != -1)
        return (INDIRECT);
    return (FALSE);
}

/* void init_my_cmd(char *cmd) */
/* { */
    
/* } */
/* char *command_to_bin(char *cmd) */
/* { */
/*     int n = 0; */
/*     int flag = 0; */
/*     char *res = NULL; */

/*     while (cmd[n] != '\0') { */
/*         flag = detect_my_cmd(cmd, (n)); */
/*         res = convert_str(flag, cmd, (n)); */
/*         n++; */
/*     } */
/*     return (res); */
/* } */

/*trouver la size final < 1 octet, une commande chaque comma*/
/*Faire un char *avec les valeurs -> array, */


/* Faire un malloc size(trouver grace a la fonction); mettre en binaire, mettre en exa / mettre en int*/
