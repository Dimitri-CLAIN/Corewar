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

int main(int ac, char **av)
{
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
<<<<<<< HEAD
    /*printf("NAME = %s\nCOMMENT = %s\nINST =\n", a.name, a.comment);
    for (int z = 0 ; a.inst[z] != NULL ; z++)
        printf("%s\n", a.inst[z]);*/
    free_my_tab(file);
    free(a.name);
    free(a.comment);
}
=======
    }
    create_my_bin(info);
    ultimate_free(info, file);
}
>>>>>>> origin/Assembler_Dimitri
