/*
** Virgile AGNEL personal project
** Random Id generator
** File description:
** random_name_gen.h
*/

#ifndef random_nam_gen_h
#define random_nam_gen_h

#define MALE (1)
#define FEMALE (2)

typedef struct path_s {
    char *path;
    struct path_s *next;
} path_t;

typedef struct info_s {
    char *last_name;
    char *first_name;
    char *age;
    char *id;
    char *city;
    char *birthday;
    char *occupation;
    char *phone;
} info_t;

int gen_data_fct(char **data, char const *flpath_pre, char const *flpath_suf);
char *my_memcat(char *dest, char *src);
void free_tab(char **tab);
char **get_pool(char const *filepath);
void free_list_env(path_t **list);
int gen_info(char **data, char const *flpath);
int get_birth_date(info_t *data);
int gen_id(info_t *data);
int male_or_female(info_t *data, unsigned short const opt);
void print_and_free(info_t *data);

#endif /* !random_name_gen_h */