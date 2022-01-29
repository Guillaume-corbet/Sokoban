/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** main
*/

#include "main.h"

void finish_second(sokoban_t *or)
{
    while (or->tab[or->zoulou][or->k] != '\n') {
        if (or->tab_stock[or->zoulou][or->k] == '1'
        && or->tab[or->zoulou][or->k] != 'X') {
            or->count_box = 1;
        }
        or->k = or->k + 1;
    }
    or->k = 0;
    or->zoulou = or->zoulou + 1;
}

int finish_first(sokoban_t *or)
{
    or->zoulou = 0;
    or->count_box = 0;
    while (or->zoulou != or->j) {
        finish_second(or);
    }
    if (or->count_box == 0) {
        return (84);
    }
    return (0);
}

int event(sokoban_t *or)
{
    or->zoulou = 0;
    or->ch = getch();
    if (or->ch == 'w') {
        return (84);
    }
    if (or->ch == ' ') {
        or->zoulou = 0;
        while (or->zoulou < or->j) {
            my_strcpy(or->tab[or->zoulou], or->save[or->zoulou]);
            or->zoulou = or->zoulou + 1;
        }
        or->zoulou = 0;
    }
    return (0);
}

int my_sokoban_second(sokoban_t *or)
{
    clear();
    refresh();
    search_player_first(or);
    while (or->zoulou != or->j) {
        mvprintw(or->zoulou, 0, or->tab[or->zoulou]);
        or->zoulou = or->zoulou + 1;
    }
    if (event(or) == 84) {
        return (84);
    }
    fonc_left_main(or);
    fonc_right_main(or);
    fonc_low_main(or);
    fonc_top_main(or);
    if (finish_first(or) == 84) {
        return (84);
    }
    return (0);
}

int main(int argc, char **argv)
{
    sokoban_t *or;
    int a = 12;

    or = malloc(sizeof(sokoban_t));
    a = my_sokoban_first(or, argc, argv);
    if (a == 84)
        return (84);
    else if (a == 0)
        return (0);
    initscr();
    while (1) {
        error_lenght(or, argc, argv);
        if (my_sokoban_second(or) == 84)
            break;
    }
    endwin();
    free;
    return 0;
}
