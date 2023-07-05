/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** main
*/
#include "../lib/my.h"

void pars(line_s *lines, char *final)
{
    if (check_space(final) != 0)
        parsing(lines, final);
    else {
        char *str = my_strconcat(final, " ");
        parsing(lines, str);
    }
    if (lines->sepa.point_virg > 0 || lines->sepa.pipe > 0)
        return;
    return;
}

int check_sep(char *line, line_s *lines)
{
    for (int i = 0; line[i] != '\0'; i++) {
        switch (line[i]) {
            case (';'):
                lines->sepa.point_virg += 1;
            case ('|'):
                lines->sepa.pipe += 1;
        }
    }
    if (lines->sepa.point_virg > 0) return (2);
    if (lines->sepa.pipe > 0) return (2);
    return (0);
}

int main(int argc, char **argv, char **env)
{
    line_s *lines = malloc(sizeof(line_s)); lines->env = env;
    init_struct(lines); char *line; char *final;
    while (1) {
        if (isatty(0) == 1) my_putstr("$> ");
        if (getline(&line, &lines->size, stdin) == -1) break;
        check_empty(line, argc, argv, lines);
        if (line == NULL) return (84); line = strtok(line, "\n");
        line = replace_tab_by_space(line);
        final = clean_space(line);
        if (check_sep(line, lines) == 2)
            parsing_sepa(lines, final);
        else
            pars(lines, final);
    } if (lines->id == 0) exit (0); free_all(lines); return (0);
}

void check_empty(char *line, int argc, char **argv, line_s *lines)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
            return;
        }
    }
    main(argc, argv, lines->env);
}
