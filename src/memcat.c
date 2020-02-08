/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** memcat.c
*/

#include "libC.h"
#include <stdlib.h>

char *my_memcat(char *dest, char *src)
{
    size_t l_one = 0;
    size_t l_two = 0;
    size_t l_three = 0;
    char *result = NULL;

    if (dest != NULL)
        for (; dest[l_one]; l_one++);
    for (; src[l_two]; l_two++);
    l_three = l_one + l_two + 1;
    result = malloc(l_three);
    if (result == NULL)
        return (NULL);
    for (l_one = 0; dest != NULL && dest[l_one] != '\0'; l_one++)
        result[l_one] = dest[l_one];
    for (l_two = 0; src != NULL && src[l_two] != '\0'; l_two++) {
        result[l_one] = src[l_two];
        l_one++;
    }
    result[l_one] = '\0';
    return (result);
}