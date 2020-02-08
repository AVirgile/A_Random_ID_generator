/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** free_list.c
*/

#include "libC.h"
#include <stdlib.h>
#include "random_name_gen.h"

void free_list_env(path_t **list)
{
    path_t *tmp = *list;
    path_t *temp = NULL;

    tmp = *list;
    while (tmp != NULL) {
        temp = tmp;
        tmp = tmp->next;
        free(temp->path);
        free(temp);
    }
    *list = NULL;
}
