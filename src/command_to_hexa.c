/*
** EPITECH PROJECT, 2019
** commande to hexa
** File description:
** commande to hexa
*/

#include "my.h"

int detect_my_cmd(char *cmd, int n)
{
    while (cmd[n] != '\0') {
        if (cmd[n] == 'r')
            return (REGISTER);
        if (cmd[n] == '%')
            return (DIRECT);
        if (my_getnbrb(cmd[n]) != -1)
            return (INDIRECT);
        n++;
    }
    return (FALSE);
}

char *convert_str(int flag, char *cmd, int n)
{
    int x = 0;

    while (cmd[n] != '\0') {
        
    }
}

int search_size(char *cmd)
{
    
}

char *command_to_hexa(char *cmd)
{
    int n = 0;
    int flag = 0;
    char *res = NULL;

    while (cmd[n] != '\0') {
        flag = detect_my_cmd(cmd, (n));
        res = convert_str(flag, cmd, (n));
        n++;
    }
    return (res);
}
/*trouver la size final, une commande chaque comma*/
