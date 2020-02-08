/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** gen_id.c
*/

#include "libC.h"
#include <stdio.h>
#include <stdlib.h>
#include <random_name_gen.h>

int gen_id(info_t *data)
{
    unsigned short random = 0;
    int i = 0;
    data->id = malloc(sizeof(char) * 12);

    if (data->id == NULL) {
        perror("id");
        return (84);
    }
    for (i = 0; i < 11; i++) {
        random = ((unsigned short) rand() % 9);
        data->id[i] = ((char) random + 48);
    }
    data->id[i] = 0;
    return (0);
}