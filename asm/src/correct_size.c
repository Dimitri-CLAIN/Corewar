/*
** EPITECH PROJECT, 2019
** correct size
** File description:
** 
*/

#include "my.h"
#include "op.h"

int do_flag_change(int flag, char **bin, int size, int *x)
{
    if (flag == REGISTER) {
        size += REG_SIZE;
        (*bin)[*x] = '0';
        (*bin)[*x + 1] = '1';
        *x += 2;
    }
    if (flag == DIRECT) {
        size += DIR_SIZE;
       (*bin)[*x] = '1';
        (*bin)[*x + 1] = '0';
        *x += 2;
    }
    if (flag == INDIRECT) {
        size += IND_SIZE;
        (*bin)[*x] = '1';
        (*bin)[*x + 1] = '1';
        *x += 2;
    }
    return (size);
}

int search_size(char **cmd, asm_t *info)
{
    int size = 0;
    int n = 0;
    int flag = 0;
    char *bin = malloc(sizeof(char) * 9);
    int x = 0;

    bin[8] = '\0';
    while (cmd[n] != NULL) {
        flag = detect_my_cmd(cmd[n]);
        size = do_flag_change(flag, &bin, size, &x);
        n++;
        flag = 0;
    }
    while (x != 8) {
        bin[x] = '0';
        x++;
    }
    
    return (size);
}
