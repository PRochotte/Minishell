/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** exec
*/
#include "../lib/my.h"

void exec(line_s *sline, char **bat, int i)
{
    if (sline->id == 0 && sline->check != 2)
        execve_exec(sline, bat, i);
}

int other_exec(line_s *sline)
{
    char *path = get_path_env(sline->env); int size = my_str_len(path);
    char new_path[size + 2];
    int check_exec = 0;
    for (int i = 0, a = 5; i != size; i++, a++) new_path[i] = path[a];
    char **bat = my_str_to_word_array(new_path, ':');
    for (int i = 0; bat[i] != NULL; i++) {
        sline->tempo_s.line = my_strconcat(bat[i], "/");
        if (sline->tempo_s.check == 0) {sline->check = 2;
            return (2);
        }
        if (stat(my_strconcat(sline->tempo_s.line, sline->tab[0]),
        &sline->tempo_s.st) == 0 && sline->check != 2) {
            sline->id = fork();
            exec(sline, bat, i);
            check_return(sline);
            return (2);
        }
    }
}

int check_space(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ')
            return (1);
    }
    return (0);
}

int unsetenv_exec(line_s *sline)
{
    if (sline->tab[1] == NULL) {
        display_env(sline);
        return (2);
    }
    for (int i = 0; sline->env[i] != NULL; i++) {
        if (my_strcmp(sline->env[i], sline->tab[1]) == 2) {
            sline->env[i] = NULL;
        }
    }
    return (2);
}

int check_env(line_s *lines)
{
    if (my_strcmp(lines->tab[0], "setenv") == 0) {
        if (lines->tab[1] == NULL) {
            display_env(lines);
            lines->check = 2;
            return (2);
        }
        my_tabconcat(lines); lines->check = 2;
        return (2);
    }
    if (my_strcmp(lines->tab[0], "unsetenv") == 0) {
        lines->check = unsetenv_exec(lines);
        return (lines->check);
    }else {
        lines->check = other_exec(lines);
    }
    return (lines->check);
}
