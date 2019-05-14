/*
** EPITECH PROJECT, 2019
** read my file
** File description:
** read a file
*/

#include "my.h"

char **read_my_file(char *file)
{
    char **map = NULL;
    size_t size = 0;
    char *buf = NULL;
    char *clean = my_strdup("");
    FILE *fd = fopen(file, "r");

    while (getline(&buf, &size, fd) != -1)
        clean = my_strcat(clean, buf);
    if (clean[my_strlen(clean) - 1] == '\n')
        clean[my_strlen(clean) - 1] = '\0';
    fclose(fd);
    map = my_str_to_all_array(clean, '\n');
    free(clean);
    return (map);
}
