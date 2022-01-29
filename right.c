/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** right
*/

#include "main.h"

void fonc_right_first(sokoban_t *or)
{
    if (or->tab[or->first_p][or->second_p + 1] != '\n'
    && or->tab[or->first_p][or->second_p + 1] == ' '
    && or->tab_stock[or->first_p][or->second_p + 1] != '1') {
        or->swap = or->tab[or->first_p][or->second_p];
        or->tab[or->first_p][or->second_p]
        = or->tab[or->first_p][or->second_p + 1];
        or->tab[or->first_p][or->second_p + 1] = or->swap;
    }
}

void fonc_right_second(sokoban_t *or)
{
    if (or->second_p != 0
    && or->tab[or->first_p][or->second_p + 1] == 'X'
    && or->tab[or->first_p][or->second_p + 2] != 'O'
    && or->tab[or->first_p][or->second_p + 2] != '#'
    && or->tab[or->first_p][or->second_p + 2] != 'X') {
        or->swap = or->tab[or->first_p][or->second_p + 1];
        or->tab[or->first_p][or->second_p + 1]
        = or->tab[or->first_p][or->second_p + 2];
        or->tab[or->first_p][or->second_p + 2] = or->swap;
        or->swap = or->tab[or->first_p][or->second_p];
        or->tab[or->first_p][or->second_p]
        = or->tab[or->first_p][or->second_p + 1];
        or->tab[or->first_p][or->second_p + 1] = or->swap;
    }
}

void fonc_right_third(sokoban_t *or)
{
    if (or->second_p != 0
    && or->tab[or->first_p][or->second_p + 1] == 'X'
    && or->tab[or->first_p][or->second_p + 2] == 'O'
    && or->tab_stock[or->first_p][or->second_p + 1] != '1') {
        or->tab[or->first_p][or->second_p + 2] = 'X';
        or->tab[or->first_p][or->second_p + 1] = ' ';
        or->swap = or->tab[or->first_p][or->second_p];
        or->tab[or->first_p][or->second_p]
        = or->tab[or->first_p][or->second_p + 1];
        or->tab[or->first_p][or->second_p + 1] = or->swap;
    }
}

void fonc_right_four(sokoban_t *or)
{
    if (or->tab_stock[or->first_p][or->second_p + 1] == '1'
    && or->tab[or->first_p][or->second_p + 2] != '#') {
        or->tab[or->first_p][or->second_p + 1] = 'P';
        or->tab[or->first_p][or->second_p] = ' ';
    }
    if (or->tab_stock[or->first_p][or->second_p] == '1'
    && or->tab[or->first_p][or->second_p + 1] == 'X'
    && or->tab[or->first_p][or->second_p + 2] == '#') {
        or->test = 0;
    } else if (or->tab_stock[or->first_p][or->second_p] == '1'
    && or->tab[or->first_p][or->second_p + 1] != '#') {
        or->tab[or->first_p][or->second_p + 1] = 'P';
        or->tab[or->first_p][or->second_p] = 'O';
    }
}

void fonc_right_main(sokoban_t *or)
{
    if (or->ch == 'C') {
        fonc_right_first(or);
        fonc_right_second(or);
        fonc_right_third(or);
        fonc_right_four(or);
        if (or->tab_stock[or->first_p][or->second_p + 1] == '1'
        && or->tab[or->first_p][or->second_p + 2] == '#'
        && or->tab[or->first_p][or->second_p + 1] != 'X') {
            or->tab[or->first_p][or->second_p + 1] = 'P';
            or->tab[or->first_p][or->second_p] = ' ';
        }
    }
}