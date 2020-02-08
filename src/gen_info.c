/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** gen_info.c
*/

#include "libC.h"
#include "random_name_gen.h"
#include <stdlib.h>

int gen_info(char **data, char const *flpath)
{
    char **names = NULL;
    int i = 0;
    int random = 0;

    names = get_pool(flpath);
    if (names == NULL)
        return (84);
    for (i = 0; names[i]; i++);
    random = rand() % i;
    *data = my_strdup(names[random]);
    free_tab(names);
    return (0);
}