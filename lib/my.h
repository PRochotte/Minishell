/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my
*/

#pragma once
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <signal.h>
#include <sys/wait.h>

int my_put_nbr(int nb);
int my_putchar(char c);
int my_putstr(const char *str);
int my_str_len(const char *str);
int conv_pos(int nb);
void my_print_alpha(void);
void my_print_revalpha(void);
void my_put_digits(void);
int my_str_to_int(char *str);
char **my_tab_concat(char **tab, char **bat);
int my_tab_len(char **tab);
char **my_str_to_word_array(char *str, char lim);
int my_strcmp(char *str, char *rts);
int my_new_str_len(char *str, int i, char lim);
char *my_strconcat(char *str, char *rts);
char *get_path_env(char **env);
char *replace_tab_by_space(char *buffer);
char *clean_space(char *buffer);

//-----------------------------Struct-------------------------------//

typedef struct line_t {
    int id;
    char *str;
    size_t size;
    int check;
    char **tab;
    char *old_path;
    char **env;
    struct tempo_t {
        struct stat st;
        char *line;
        int check;
        int status;
    }tempo_s;
    int return_value;
    struct sepa_t {
        int point_virg;
        int pipe;
    } sepa;
}line_s;

//-----------------------------Main  Function-----------------------------//

int other_exec(line_s *line);
void init_struct(line_s *line);
int check_space(char *line);
void parsing(line_s *lines, char *line);
int check_env(line_s *lines);
int cd_exec(line_s *sline);
void display_env(line_s *lines);
void check_empty(char *line, int argc, char **argv, line_s *lines);
int execve_exec(line_s *sline, char **bat, int i);
void *my_tabconcat(line_s *lines);
void parsing_sepa(line_s *lines, char *line);
void pars(line_s *lines, char *final);
void check_return(line_s *sline);
void init_struct(line_s *line);
void free_all(line_s *lines);
