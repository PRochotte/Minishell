/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** separateur
*/

#include "../lib/my.h"

void parsing_sepa(line_s *lines, char *line)
{
    char *buffer = malloc(sizeof(char) * my_str_len(line) +
    lines->sepa.point_virg);
    buffer = replace_tab_by_space(line);
    buffer = clean_space(line);
    int i = 0; int a = 0;
    for (; line[i] != '\0'; i++, a++) {
        if (line[i] == ';' && line[i + 1] == ' ') {
            buffer[a] = line[i];
            i += 1;
        } else {
            buffer[a] = line[i];
            buffer[a + 1] = ' ';
        }
    }
    char **tab = my_str_to_word_array(buffer, ';');
    for (int i = 0; tab[i] != NULL; i++) {
        pars(lines, tab[i]);
    }
}
