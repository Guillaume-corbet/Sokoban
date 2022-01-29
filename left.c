/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** left
*/

#include "main.h"

void fonc_left_first(sokoban_t *or)
{
    if (or->second_p != 0
    && or->tab[or->first_p][or->second_p - 1] == ' '
    && or->tab_stock[or->first_p][or->second_p - 1] != '1') {
        or->swap = or->tab[or->first_p][or->second_p];
        or->tab[or->first_p][or->second_p]
        = or->tab[or->first_p][or->second_p - 1];
        or->tab[or->first_p][or->second_p - 1] = or->swap;
    }
    if (or->second_p != 0
    && or->tab[or->first_p][or->second_p - 1] == 'O') {
        or->tab[or->first_p][or->second_p] = ' ';
        or->tab[or->first_p][or->second_p - 1] = 'P';
    }
}

void fonc_left_second(sokoban_t *or)
{
    if (or->second_p != 0
    && or->tab[or->first_p][or->second_p - 1] == 'X'
    && or->tab[or->first_p][or->second_p - 2] != 'O'
    && or->tab[or->first_p][or->second_p - 2] != '#'
    && or->tab[or->first_p][or->second_p - 2] != 'X') {
        or->swap = or->tab[or->first_p][or->second_p - 1];
        or->tab[or->first_p][or->second_p - 1]
        = or->tab[or->first_p][or->second_p - 2];
        or->tab[or->first_p][or->second_p - 2] = or->swap;
        or->swap = or->tab[or->first_p][or->second_p];
        or->tab[or->first_p][or->second_p]
        = or->tab[or->first_p][or->second_p - 1];
        or->tab[or->first_p][or->second_p - 1] = or->swap;
    }
}

void fonc_left_third(sokoban_t *or)
{
    if (or->second_p != 0
    && or->tab[or->first_p][or->second_p - 1] == 'X'
    && or->tab[or->first_p][or->second_p - 2] == 'O'
    && or->tab_stock[or->first_p][or->second_p - 1] != '1') {
        or->tab[or->first_p][or->second_p - 2] = 'X';
        or->tab[or->first_p][or->second_p - 1] = ' ';
        or->swap = or->tab[or->first_p][or->second_p];
        or->tab[or->first_p][or->second_p]
        = or->tab[or->first_p][or->second_p - 1];
        or->tab[or->first_p][or->second_p - 1] = or->swap;
    }
}

void fonc_left_four(sokoban_t *or)
{
    if (or->tab_stock[or->first_p][or->second_p - 1] == '1'
    && or->tab[or->first_p][or->second_p - 2] != '#') {
        or->tab[or->first_p][or->second_p - 1] = 'P';
        or->tab[or->first_p][or->second_p] = ' ';
    }
    if (or->tab_stock[or->first_p][or->second_p] == '1'
    && or->tab[or->first_p][or->second_p - 1] == 'X'
    && or->tab[or->first_p][or->second_p - 2] == '#') {
        or->test = 0;
    } else if (or->tab_stock[or->first_p][or->second_p] == '1'
    && or->tab[or->first_p][or->second_p - 1] != '#') {
        or->tab[or->first_p][or->second_p - 1] = 'P';
        or->tab[or->first_p][or->second_p] = 'O';
    }
}

void fonc_left_main(sokoban_t *or)
{
    if (or->ch == 'D') {
        fonc_left_first(or);
        fonc_left_second(or);
        fonc_left_third(or);
        fonc_left_four(or);
        if (or->tab_stock[or->first_p][or->second_p - 1] == '1'
        && or->tab[or->first_p][or->second_p - 2] == '#'
        && or->tab[or->first_p][or->second_p - 1] != 'X') {
            or->tab[or->first_p][or->second_p - 1] = 'P';
            or->tab[or->first_p][or->second_p] = ' ';
        }
    }
}