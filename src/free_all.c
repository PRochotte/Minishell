/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** free_all
*/
#include "../lib/my.h"

void free_all(line_s *lines)
{
    free(lines->tempo_s.line);
    free(lines->old_path);
    free(lines->str);
    for (int i = 0; lines->tab[i] != NULL; i++)
        free(lines->tab[i]);
    free(lines->tab);
    for (int i = 0; lines->env[i] != NULL; i++)
        free(lines->env[i]);
    free(lines->env);
    free(lines);
}
