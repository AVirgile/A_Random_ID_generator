/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** birthday.c
*/

#include "libC.h"
#include "random_name_gen.h"
#include <time.h>
#include <stdlib.h>

static char *my_spacecat(char *dest, char *src, unsigned short const release)
{
    size_t l_one = my_strlen(dest) + 1;
    size_t l_two = my_strlen(src);
    size_t l_three = l_one + l_two + 1;
    char *result = malloc(l_three);

    if (result == NULL)
        return (NULL);
    for (l_one = 0; dest != NULL && dest[l_one] != '\0'; l_one++)
        result[l_one] = dest[l_one];
    result[l_one] = ' ';
    for (l_two = 0; src != NULL && src[l_two] != '\0'; l_two++, l_one++)
        result[l_one + 1] = src[l_two];
    result[l_one + 1] = '\0';
    if (release == 1)
        free(dest);
    return (result);
}

static int get_cur_year(char *date)
{
    char *buffer = my_strtok(date, "\n");
    char *year = malloc(sizeof(char) * 5);
    int length = my_strlen(buffer) - 1;
    int result = 0;
    int i = 0;

    if (year == NULL)
        return (-1);
    for (i = 0; i < 4; i++)
        year[i] = buffer[length - i];
    year[i] = 0;
    year = my_revstr(year);
    result = my_getnbr(year);
    free(year);
    return (result);
}

static int get_current_date(info_t *data)
{
    time_t current_time;
    char *date = NULL;
    int year = 0;

    time(&current_time);
    date = ctime(&current_time);
    year = get_cur_year(date) - my_getnbr(data->age);
    if (year < 0)
        return (84);
    return (year);
}

int get_birth_date(info_t *data)
{
    int year = get_current_date(data);
    char *release = NULL;
    char **day = get_pool("src/pool/day");
    char **month = get_pool("src/pool/month");
    int i = 0;
    int j = 0;
    int rand_day = 0;
    int rand_month = 0;

    for (i = 0; day[i]; i++);
    for (j = 0; month[j]; j++);
    rand_day = rand() % i;
    rand_month = rand() % j;
    data->birthday = my_spacecat(day[rand_day], month[rand_month], 0);
    release = my_itoa(year);
    data->birthday = my_spacecat(data->birthday, release, 1);
    free_tab(day);
    free_tab(month);
    free(release);
    return (0);
}
