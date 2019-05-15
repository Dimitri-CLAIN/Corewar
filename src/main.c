/*
** EPITECH PROJECT, 2019
** main
** File description:
** corwar main
*/

#include "my.h"

void ultimate_free(asm_t *info, char **file)
{
    free_my_tab(file);
    free(info->name);
    free(info->comment);
}

int my_hextoia(int nb)
{
    int decimal_number = 0;
    int rem = 0;
    int count = 0;
    int pow = 0;
    int n = 0;

    while(nb > 0) {
        rem = nb % 10;
        while (n != 16) {
            pow = 16 * count;
            n++;
        }
        printf("pow -> %d / count = \n", pow);
        decimal_number = decimal_number + rem * pow;
        nb = nb / 10;
        count++;
    }
    printf("%d\n", decimal_number);
    return (decimal_number);
}

int main(int ac, char **av)
{
//    printf("%d\n", my_hextoia(02));
    char **file = NULL;
    asm_t *info = malloc(sizeof(asm_t));

    if (av[1] == NULL) {
        free(info);
        return (84);
    }
    file = read_my_file(av[1]);
    if (check_file(file, info) == 84) {
        ultimate_free(info, file);
        return (84);
    }
    create_my_bin(info);
    printf("final = %d\n", search_size(my_str_to_all_array(info->inst[2], ','), info));
    ultimate_free(info, file);
}
