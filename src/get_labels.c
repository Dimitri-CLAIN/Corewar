/*
** EPITECH PROJECT, 2019
** get
** File description:
** labels
*/

#include "my.h"
/*
int get_labels_nb(char **file)
{
    int y = 0;
    int len = 0;

    for (int i = 0; file[i] != NULL; i++) {
        for (y = 0; file[i][y] != '\0' && file[i][y] != SEPARATOR_CHAR
            && file[i][0] != COMMENT_CHAR && file[i][y] != LABEL_CHAR; y++);
        if (file[i][y] == LABEL_CHAR)
            len++;
    }
    return (len);
}

char **take_labels_inst(char *line)
{
    char **out = NULL;

    while (line[0] != ':' && line[0] != '\0')
        line = line + 1;
    if (line[0] == '\0' || line[1] == '\0')
        return (NULL);
    line += 1;
    line = my_clean_str(line);
    out = my_str_to_all_array(line, ',');
    for (int i = 0; out[i] != NULL; i++)
        out[i] = my_clean_str(out[i]);
    return (out);
}

char *take_labels_name(char *line)
{
    char *out = NULL;
    int len = 0;
    int i = 0;

    line = my_clean_str(line);
    for (len = 0; line[len] != '\0' && line[len] != ':'; len++);
    out = malloc(sizeof(char) * (len + 1));
    for (i = 0; i != len; i++)
        out[i] = line[i];
    out[i] = '\0';
    return (out);
}

int take_labels_nb(char **file, asm_t *a)
{
    int y = 0;
    int len = 0;
    int j = 0;

    for (int i = 0; file[i] != NULL; i++) {
        for (y = 0; file[i][y] != '\0' && file[i][y] != SEPARATOR_CHAR
            && file[i][0] != COMMENT_CHAR && file[i][y] != LABEL_CHAR; y++);
        if (file[i][y] == LABEL_CHAR) {
            a->labels[j]->pos = i;
            a->labels[j]->inst = take_labels_inst(file[i]);
            a->labels[j]->name = take_labels_name(file[i]);
            j = j + 1;
        }
    }
    return (0);
}

int get_labels(char **file, asm_t *a)
{
    int i = 0;
    int len = get_labels_nb(file);

    if (len == 0) {
    a->labels = NULL;
    return (0);
    }
    a->labels = malloc(sizeof(labels_t *) * (len + 1));
    for (i = 0; i != len != NULL; i++)
        a->labels[i] = malloc(sizeof(labels_t));
    a->labels[i] = NULL;
    take_labels_nb(file, a);
    return (0);
}*/