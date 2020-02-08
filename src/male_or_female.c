/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** male_or_female.c
*/

#include "random_name_gen.h"

int male_or_female(info_t *data, unsigned short const opt)
{
    if (opt == MALE) {
        if (gen_info(&data->first_name,
                     "src/pool/first_name_male") == 84) return (84);
    }
    else if (opt == FEMALE) {
        if (gen_info(&data->first_name,
                     "src/pool/first_name_female") == 84) return (84);
    }
    return (0);
}