/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** len
*/

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}