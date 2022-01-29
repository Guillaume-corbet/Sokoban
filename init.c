/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** init
*/

#include "main.h"

void initialisation(sokoban_t *or, int argc, char **argv)
{
    or->charac = 96;
    stat(argv[1], &or->buf);
    or->size = or->buf.st_size;
    or->str = malloc(sizeof(char) * or->size + 1);
    or->fd = open(argv[1], O_RDONLY);
    read(or->fd, or->str, or->size);
    close(or->fd);
    or->str[or->size] = '\0';
    define_malloc_first(or);
    or->save = malloc(sizeof(char *) * or->size_mal + 1);
    or->tab = malloc(sizeof(char *) * or->size_mal + 1);
    or->tab_stock = malloc(sizeof(char *) * or->size_mal + 1);
    or->y = or->size_mal;
}

void double_tab(sokoban_t *or, int argc, char **argv)
{
    while (or->str[or->i] != '\0') {
        define_malloc_second(or);
        or->save[or->j] = malloc(sizeof(char) * or->size_mal + 1);
        or->tab[or->j] = malloc(sizeof(char) * or->size_mal + 1);
        or->tab_stock[or->j] = malloc(sizeof(char) * or->size_mal + 1);
        while (or->str[or->i] != '\n') {
            or->save[or->j][or->k] = or->str[or->i];
            or->tab[or->j][or->k] = or->str[or->i];
            or->k = or->k + 1;
            or->i = or->i + 1;
        }
        or->stock = or->k;
        or->save[or->j][or->k] = '\n';
        or->tab[or->j][or->k] = '\n';
        or->i = or->i + 1;
        or->j = or->j + 1;
        or->k = 0;
    }
}

void search_player_second(sokoban_t *or)
{
    while (or->tab[or->zoulou][or->k] != '\n') {
        if (or->tab[or->zoulou][or->k] == 'P') {
            or->first_p = or->zoulou;
            or->second_p = or->k;
        }
        or->k = or->k + 1;
    }
    or->k = 0;
    or->zoulou = or->zoulou + 1;
}

void search_stock(sokoban_t *or)
{
    while (or->tab[or->zoulou][or->k] != '\n') {
        if (or->tab[or->zoulou][or->k] == 'O') {
            or->tab_stock[or->zoulou][or->k] = '1';
        } else if (or->tab[or->zoulou][or->k] == 'X') {
            or->tab_stock[or->zoulou][or->k] = '2';
        } else {
            or->tab_stock[or->zoulou][or->k] = '0';
        }
        or->k = or->k + 1;
    }
    or->k = 0;
    or->zoulou = or->zoulou + 1;
}

void search_player_first(sokoban_t *or)
{
    or->k = 0;
    or->zoulou = 0;
    while (or->zoulou < or->j) {
        search_player_second(or);
    }
    or->zoulou = 0;
    or->k = 0;
    while (or->zoulou < or->j && or->count != or->j) {
        search_stock(or);
        or->count = or->count + 1;
    }
    or->zoulou = 0;
    or->k = 0;
}