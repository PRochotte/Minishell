/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** clean
*/
#include "../lib/my.h"

int cd_exec(line_s *sline)
{
    if (sline->tab[1] == NULL) {
        my_putstr("cd: Too few arguments.\n"); return (2);
    }
    if (sline->tab[1][0] == '-' && sline->tab[1][1] == '\0') {
        if (sline->old_path == NULL) {
            my_putstr("bash: cd: OLDPWD not set\n"); return (2);
        }
        my_putstr (sline->old_path); my_putchar('\n');
        chdir(sline->old_path);
        return (2);
    }
    sline->old_path = getcwd(sline->old_path, 128);
    chdir(sline->tab[1]); return (2);
    return (0);
}

char *replace_tab_by_space(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\t') buffer[i] = ' ';
    } return (buffer);
}

char *clean_space(char *buffer)
{
    int i = 0; int j = 0;
    char *clean = malloc(sizeof(char) * my_str_len(buffer) + 1);
    while (buffer[i] == ' ') i++;
    while (buffer[i] != '\0') {
        if (buffer[i] == ' ' && (buffer[i + 1] == ' ' ||
        buffer[i + 1] == '\0')) i++;
        else {
            clean[j] = buffer[i];
            i++; j++;
        }
    } clean[j] = '\0';
    return (clean);
}

void display_env(line_s *lines)
{
    for (int i = 0; lines->env[i] != NULL; i++) {
        my_putstr(lines->env[i]); my_putchar('\n');
    }
}
