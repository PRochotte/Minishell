/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** concat
*/
#include "../lib/my.h"

void concat_env(line_s *line, char *lines)
{
    char *temp;
    int size = 0;
    char **new_env;
    for (int i = 0; line->env[i] != NULL; i++) size++;
    new_env = malloc(sizeof(char *) * (size + 2));
    for (int i = 0; line->env[i] != NULL; i++) {
        new_env[i] = line->env[i];
    }
    new_env[size] = lines;
    new_env[size + 1] = NULL;
    line->env = new_env;
}

char *enleve_le_dernier(char *temp)
{
    int i = 0;
    for (i = 0; temp[i] != '\0'; i++);
    temp[i - 1] = '\0';
    return (temp);
}

void *my_tabconcat(line_s *lines)
{
    char *temp;
    int size = 0;
    for (int i = 1; lines->tab[i] != NULL; i++) {
        for (int j = 0; lines->tab[i][j] != '\0'; j++) size++;
        size++;
    }
    temp = malloc(sizeof(char) * size + 1);
    for (int i = 1; lines->tab[i] != NULL; i++) {
        temp = my_strconcat(temp, lines->tab[i]);
        if (lines->tab[i][0] != '\0')
            temp = my_strconcat(temp, "=");
    } temp = enleve_le_dernier(temp);
    concat_env(lines, temp);
}
