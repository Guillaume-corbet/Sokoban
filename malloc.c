/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** malloc
*/

#include "main.h"

void define_malloc_first(sokoban_t *or)
{
    or->size_mal_max = 0;
    or->z = 0;
    while (or->str[or->z] != '\0') {
        if (or->str[or->z] == '\n') {
            or->size_mal = or->size_mal + 1;
        }
        or->z = or->z + 1;
    }
    or->z = 0;
}

void define_malloc_second(sokoban_t *or)
{
    or->x = 0;
    while (or->str[or->z] != '\0') {
        if (or->str[or->z] == '\n') {
            or->size_mal = or->x;
            break;
        }
        if (or->size_mal_max < or->size_mal) {
            or->size_mal_max = or->size_mal;
        }
        or->z = or->z + 1;
        or->x = or->x + 1;
    }
}