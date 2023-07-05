/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** init
*/
#include "../lib/my.h"

void init_struct(line_s *line)
{
    line->id = 1;
    line->check = 0; line->size = 0;
    line->old_path = NULL;
    line->tempo_s.check = -1;
    line->tempo_s.status = 0;
    line->return_value = 0;
    line->sepa.point_virg = 0;
    line->sepa.pipe = 0;
}
