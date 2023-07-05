/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_str_to_word_array
*/
#include "my.h"

int my_str_to_int(char *str)
{
    int nb = 0;
    int i = 0;
    for (i; str[i] != '\0'; i++) {
        char a = str[i];
        nb = ((nb + (int)a) * 10) - 480;
    }
    nb = nb / 10;
    return (nb);
}

char **my_tab_concat(char **tab, char **bat)
{
    int a = my_tab_len(tab);
    int b = my_tab_len(bat);
    int i; int j; int c = a + b + 1;
    char **result = malloc(sizeof(char *) * (c));
    for (i = 0; tab[i] != NULL; i++)
        result[i] = tab[i];
    for (j = 0; bat[j] != NULL; j++) {
        result[i] = bat[j];
        i++;
    }
    return (result);
}

int my_strcmp(char *str, char *rts)
{
    int a = my_str_len(str);
    int b = my_str_len(rts);
    if (a != b)
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != rts[i]) {
            return (1);
        }
    }
    return (0);
}

char *my_strconcat(char *str, char *rts)
{
    int a = my_str_len(str);
    int b = my_str_len(rts);
    int i;
    int j;
    int c = a + b + 1;
    char *result = malloc(sizeof(char *) * (c));
    for (i = 0; str[i] != '\0'; i++) {
        result[i] = str[i];
    }
    for (j = 0; rts[j] != '\0'; j++) {
        result[i] = rts[j];
        i++;
    }
    return (result);
}

char *get_path_env(char **env)
{
    char *result;
    int line = 0;
    int i = 0;
    for (i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
        && env[i][3] == 'H') {
            line = my_str_len(env[i]);
            break;
        }
    }
    return (env[i]);
}
