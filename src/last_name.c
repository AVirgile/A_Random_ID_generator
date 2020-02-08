/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** last_name.c
*/

#include "libC.h"
#include "random_name_gen.h"
#include <stdlib.h>

int gen_data_fct(char **data, char const *flpath_pre, char const *flpath_suf)
{
    char **pre = NULL;
    char **suf = NULL;
    int i = 0;
    int j = 0;
    int rand_pre = 0;
    int rand_suf = 0;

    pre = get_pool(flpath_pre);
    suf = get_pool(flpath_suf);
    if (suf == NULL || pre == NULL)
        return (84);
    for (i = 0; pre[i]; i++);
    for (j = 0; suf[j]; j++);
    rand_pre = rand() % i;
    rand_suf = rand() % j;
    *data = my_memcat(pre[rand_pre], suf[rand_suf]);
    free_tab(pre);
    free_tab(suf);
    return (0);
}

