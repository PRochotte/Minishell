/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my
*/

#include "my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

int my_put_nbr(int nb)
{
    if ( nb < 0 ){
        my_putchar ('-');
        nb *= -1;
    }
    int compt = 0;
    int c;
    int div = 1;
    for (c = nb; c >= 10; c /= 10, div *= 10);
    while ( div >= 1) {
        my_putchar (( nb / div) % 10 + '0');
        div /= 10;
        compt += 1;
    }
}

int my_str_len(const char *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int conv_pos(int nb)
{
    if (nb < 0) {
        nb *= (-1);
    } else {
        return (nb);
    }
    return (nb);
}
