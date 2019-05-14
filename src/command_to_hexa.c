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

/* char *convert_str(int flag, char *cmd, int n) */
/* { */
/*     int x = 0; */

/*     while (cmd[n] != '\0') { */
        
/*     } */
/* } */

/* char *command_to_hexa(char *cmd) */
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
