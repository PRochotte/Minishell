/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** parsing
*/
#include "../lib/my.h"

void change(line_s *sline, int i)
{
    if (sline->tab[i][0] == '.' && sline->tab[i][1] == '/') {
        for (int j = 0; sline->tab[i][j] != '\0'; j++) {
            sline->tab[i][j] = sline->tab[i][j + 2];
        }
    }
}

int check_command(line_s *sline)
{
    for (int i = 0; sline->tab[i] != NULL; i++) {
        change(sline, i);
    }
    other_exec(sline);
}

int parsing_suite(line_s *sline)
{
    if (my_strcmp(sline->tab[0], "cd") == 0) {
        sline->check = cd_exec(sline); return (2);
    }
    if (my_strcmp(sline->tab[0], "exit") == 0) {
        my_putstr("exit\n"); sline->check = 2;
        if (sline->id == 0) exit(0);
        exit(sline->return_value);
    }
    if (my_strcmp(sline->tab[0], "env") == 2) {
        for (int i = 0; sline->env[i] != NULL; i++) {
            my_putstr(sline->env[i]); my_putchar('\n');
        } return (2);
    } check_env(sline);
    if (sline->check == 2) return (2); check_command(sline);
}

void parsing(line_s *lines, char *line)
{
    lines->tab = my_str_to_word_array(line, ' ');
    lines->check = parsing_suite(lines);
    if (lines->check == 0) {
        for (int i = 0; lines->tab[i] != NULL; i++) {
            my_putstr(lines->tab[i]); my_putchar(' ');
        }
        my_putstr("\b: Command not found.\n");
    }
    lines->check = 0;
}

int execve_exec(line_s *sline, char **bat, int i)
{
    if (sline->id == 0) {
        sline->check = execve(my_strconcat(sline->tempo_s.line, sline->tab[0]),
        sline->tab, sline->env);
        exit(0);
    }
}
