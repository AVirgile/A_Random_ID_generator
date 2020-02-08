/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** load_pool.c
*/

#include "libC.h"
#include <stdlib.h>
#include <stdio.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

static void end_get_pre_suf(char **buffer, FILE **fd)
{
    free(*buffer);
    fclose(*fd);
}

static size_t get_file_height(char const *filepath)
{
    FILE *stream = fopen(filepath, "r");
    size_t size = 0;
    char *buffer = NULL;
    size_t n = 0;

    for (; getline(&buffer, &n, stream) > 0; size++);
    free(buffer);
    fclose(stream);
    return (size);
}

char **get_pool(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    size_t height = get_file_height(filepath);
    char **result = malloc(sizeof(char *) * (height + 1));
    size_t i = 0;
    int line = 0;
    char *buffer = NULL;
    char *remove = NULL;
    int stock = getline(&buffer, &i, fd);

    while (stock >= 0) {
        remove = my_strtok(buffer, "\n");
        result[line] = my_strdup(remove);
        line++;
        free(buffer);
        buffer = NULL;
        i = 0;
        stock = getline(&buffer, &i, fd);
    }
    result[line] = NULL;
    end_get_pre_suf(&buffer, &fd);
    return (result);
}
