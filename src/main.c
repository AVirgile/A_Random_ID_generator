/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** main.c
*/

#include "libC.h"
#include <stdlib.h>
#include <time.h>
#include "random_name_gen.h"
#include <stdio.h>
#include <unistd.h>

static void add_node_end(path_t **list, char *path)
{
    path_t *node = malloc(sizeof(path_t));
    path_t *tmp = *list;

    node->path = my_strdup(path);
    node->next = NULL;
    if (*list == NULL) {
        *list = node;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
}

static int core_fct(unsigned short const opt)
{
    info_t data;

    if (gen_data_fct(&data.last_name, "src/pool/last_name_pre",
            "src/pool/last_name_suf") == 84)
        return (84);
    if (male_or_female(&data, opt) == 84)
        return (84);
    if (gen_info(&data.age, "src/pool/age") == 84)
        return (84);
    if (get_birth_date(&data) == 84)
        return (84);
    if (gen_info(&data.city, "src/pool/city") == 84)
        return (84);
    if (gen_info(&data.occupation, "src/pool/occupation") == 84)
        return (84);
    if (gen_info(&data.phone, "src/pool/mobile") == 84)
        return (84);
    if (gen_id(&data) == 84)
        return (84);
    print_and_free(&data);
    return (0);
}

static int create_list(path_t **list)
{
    FILE *fd = NULL;
    size_t i = 0;
    char *buffer = NULL;
    char *remove = NULL;

    fd = fopen("src/pool/.security", "r");
    if (fd == NULL) {
        perror(".security");
        return (84);
    }
    while (getline(&buffer, &i, fd) > 0) {
        remove = my_strtok(buffer, "\n");
        add_node_end(list, remove);
        free(buffer);
        buffer = NULL;
    }
    free(buffer);
    fclose(fd);
    return (0);
}

static int check_all_pool_file(void)
{
    path_t *list = NULL;

    if (create_list(&list) == 84)
        return (84);
    for (path_t *check = list; check != NULL; check = check->next) {
        if (access(check->path, F_OK) == -1) {
            perror(check->path);
            my_werror("This essential pool file does not exist"
                      " or is not in the right directory\n");
            return (84);
        }
    }
    free_list_env(&list);
    return (0);
}

int main(int const argc, char const **argv)
{
    if (argc == 2) {
        srand(time(NULL));
        if (check_all_pool_file() == 84)
            return (84);
        if (my_getnbr(argv[1]) == MALE) {
            if (core_fct(1) == 84) return (84);
            return (0);
        }
        else if (my_getnbr(argv[1]) == FEMALE) {
            if (core_fct(2) == 84) return (84);
            return (0);
        }
        else {
            my_werror("Wrong option only option accepted are"
                      " one for male and 2 for female\n");
            return (84);
        }
    }
    my_werror("An integer must be passed as only arguments in"
              " this program 1 for a male and 2 for a female\n");
    return (84);
}