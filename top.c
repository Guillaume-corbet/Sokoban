/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** top
*/

#include "main.h"

void fonc_top_first(sokoban_t *or)
{
    if (or->first_p != 0
    && or->tab[or->first_p - 1][or->second_p] == ' '
    && or->tab_stock[or->first_p - 1][or->second_p] != '1') {
        or->swap = or->tab[or->first_p][or->second_p];
        or->tab[or->first_p][or->second_p]
        = or->tab[or->first_p - 1][or->second_p];
        or->tab[or->first_p - 1][or->second_p] = or->swap;
    }
}

void fonc_top_second(sokoban_t *or)
{
    if (or->first_p != 0
    && or->tab[or->first_p - 1][or->second_p] == 'X'
    && or->tab[or->first_p - 2][or->second_p] != 'O'
    && or->tab[or->first_p - 2][or->second_p] != '#'
    && or->tab[or->first_p - 2][or->second_p] != 'X') {
        or->swap = or->tab[or->first_p - 1][or->second_p];
        or->tab[or->first_p - 1][or->second_p]
        = or->tab[or->first_p - 2][or->second_p];
        or->tab[or->first_p - 2][or->second_p] = or->swap;
        or->swap = or->tab[or->first_p][or->second_p];
        or->tab[or->first_p][or->second_p]
        = or->tab[or->first_p - 1][or->second_p];
        or->tab[or->first_p - 1][or->second_p] = or->swap;
    }
}

void fonc_top_third(sokoban_t *or)
{
    if (or->first_p != 0
    && or->tab[or->first_p - 1][or->second_p] == 'X'
    && or->tab[or->first_p - 2][or->second_p] == 'O'
    && or->tab_stock[or->first_p - 1][or->second_p] != '1') {
        or->tab[or->first_p - 2][or->second_p] = 'X';
        or->tab[or->first_p - 1][or->second_p] = ' ';
        or->swap = or->tab[or->first_p][or->second_p];
        or->tab[or->first_p][or->second_p]
        = or->tab[or->first_p - 1][or->second_p];
        or->tab[or->first_p - 1][or->second_p] = or->swap;
    }
}

void fonc_top_four(sokoban_t *or)
{
    if (or->tab_stock[or->first_p - 1][or->second_p] == '1'
    && or->tab[or->first_p - 2][or->second_p] != '#') {
        or->tab[or->first_p - 1][or->second_p] = 'P';
        or->tab[or->first_p][or->second_p] = ' ';
    }
    if (or->tab_stock[or->first_p][or->second_p] == '1'
    && or->tab[or->first_p - 1][or->second_p] == 'X'
    && or->tab[or->first_p - 2][or->second_p] == '#') {
        or->test = 0;
    } else if (or->tab_stock[or->first_p][or->second_p] == '1'
    && or->tab[or->first_p - 1][or->second_p] != '#') {
        or->tab[or->first_p - 1][or->second_p] = 'P';
        or->tab[or->first_p][or->second_p] = 'O';
    }
}

void fonc_top_main(sokoban_t *or)
{
    if (or->ch == 'A') {
        fonc_top_first(or);
        fonc_top_second(or);
        fonc_top_third(or);
        fonc_top_four(or);
        if (or->tab_stock[or->first_p - 1][or->second_p] == '1'
        && or->tab[or->first_p - 2][or->second_p] == '#'
        && or->tab[or->first_p - 1][or->second_p] != 'X') {
            or->tab[or->first_p - 1][or->second_p] = 'P';
            or->tab[or->first_p][or->second_p] = ' ';
        }
    }
}