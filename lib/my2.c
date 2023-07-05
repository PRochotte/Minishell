/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my2
*/
#include "my.h"

void my_print_alpha(void)
{
    for (char letter = 'a'; letter <= 'z'; letter++) {
        my_putchar(letter);
    }
}

void my_print_revalpha(void)
{
    for (char letter = 'z'; letter >= 'a'; letter--) {
        my_putchar(letter);
    }
}

void my_put_digits(void)
{
    for (int digits = 0; digits <= 9; digits++) {
        my_put_nbr(digits);
        my_putchar('\n');
    }
}

int my_new_str_len(char *str, int i, char lim)
{
    for (i = 0; str[i] != lim; i++);
    return (i);
}

int my_tab_len(char **tab)
{
    int i = 0;
    for (i; tab[i] != NULL; i++);
    return (i);
}
