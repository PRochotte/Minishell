/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** return
*/
#include "../lib/my.h"

void check_return(line_s *sline)
{
    if (waitpid(sline->id, &sline->tempo_s.status, 0)) return;
    else {
        if (waitpid(sline->id, &sline->tempo_s.status, 139)) {
            my_putstr("Segmentation fault\n"); sline->return_value = 139;
        }
        if (waitpid(sline->id, &sline->tempo_s.status, 136)) {
            my_putstr("Floating exception\n"); sline->return_value = 136;
        }
        if (waitpid(sline->id, &sline->tempo_s.status, 134)) {
            my_putstr("Abort\n"); sline->return_value = 134;
        }
        if (waitpid(sline->id, &sline->tempo_s.status, 131)) {
            my_putstr("Bus error\n"); sline->return_value = 131;
        }
        if (waitpid(sline->id, &sline->tempo_s.status, 126)) {
            my_putstr("Permission denied\n"); sline->return_value = 126;
        }
    }
}
