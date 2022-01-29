/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** other
*/

#include "main.h"

int my_sokoban_first(sokoban_t *or, int argc, char **argv)
{
    if (error_init(or, argc, argv) == 84)
        return (84);
    if (usage(or, argc, argv) == 84)
        return (0);
    or->count = 0;
    initialisation(or, argc, argv);
    double_tab(or, argc, argv);
    if (error_middle(or, argc, argv) == 84)
        return (84);
    return (5);
}

int my_sokoban_third(sokoban_t *or)
{
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
}