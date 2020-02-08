/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** printf_and_free.c
*/

#include "libC.h"
#include <stdlib.h>
#include "random_name_gen.h"

void print_and_free(info_t *data)
{
    my_printf("LAST NAME: %s\n", data->last_name);
    my_printf("FIRST NAME: %s\n", data->first_name);
    my_printf("AGE: %s\n", data->age);
    my_printf("BIRTHDAY: %s\n", data->birthday);
    my_printf("CITY: %s\n", data->city);
    my_printf("OCCUPATION: %s\n", data->occupation);
    my_printf("PHONE: %s\n", data->phone);
    my_printf("ID: %s\n", data->id);
    free(data->phone);
    free(data->id);
    free(data->occupation);
    free(data->last_name);
    free(data->first_name);
    free(data->age);
    free(data->birthday);
    free(data->city);
}