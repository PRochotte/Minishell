/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_str_to_word_array
*/

#include "my.h"

char **suite(char **result, char *str, int lengh, char lim)
{
    int j = 0;
    int b = 0;
    int a = 0;
    int z = 0;
    int wordlengh = 0;
    for (int i = 0, a = 0; i <= lengh && str[j] != '\0'; a++, b++, j++) {
        for (j; str[j] != lim && str[j] != '\0'; j++, wordlengh++);
        result[a] = malloc(sizeof(char) * (wordlengh + 1));
        i += wordlengh;
        for (b; str[b] != lim && str[b] != '\0'; b++, z++)
            result[a][z] = str[b];
        result[a][z] = '\0';
        z = 0;
        wordlengh = 0;
    }
    return (result);
}

char **my_str_to_word_array(char *str, char lim)
{
    int nb_word = 1;
    int lengh = my_str_len(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == lim)
            nb_word++;
    }
    if (str[lengh - 1] == lim)
        nb_word -= 1;
    char **result = malloc(sizeof(char *) * (nb_word + 1));
    suite(result, str, lengh, lim);
    result[nb_word] = NULL;
    return (result);
}
