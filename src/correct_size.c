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

int check_bin(char *bin)
{
    int n = 0;
    int co = 0;

    while (bin[n] != '\0') {
        if (bin[n] == '1')
            co++;
        n++;
    }
    if (co <= 2)
        return (FALSE);
    return (TRUE);
}

coding_style_t *search_coding_byte(char **cmd, asm_t *info)
{
    int size = 0;
    int n = 0;
    int flag = 0;
    char *bin = malloc(sizeof(char) * 9);
    int x = 0;
    coding_style_t *code = malloc(sizeof(*code));

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
    if (check_bin(bin) != FALSE)
        code->code = my_bintoi(bin);
    else
        code->code = NULL;
    code->bin = bin;
    return (code);
}
//24 ligne
