/*
** EPITECH PROJECT, 2019
** correct size
** File description:
** correct size
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

int check_bin(char *name)
{
    if (my_strcmp(name, "live") == TRUE || my_strcmp(name, "zjmp") == TRUE ||
    my_strcmp(name, "lfork") == TRUE || my_strcmp(name, "fork") == TRUE)
        return (FALSE);
    return (TRUE);
}

void init_code(char *name, char *bin, coding_style_t *code)
{
    if (check_bin(name) != FALSE)
        code->code = my_bintoi(bin);
    else
        code->code = 0;
    code->bin = bin;
}

coding_style_t *search_coding_byte(char **cmd, asm_t *info, char *name)
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
    init_code(name, bin, code);
    return (code);
}
