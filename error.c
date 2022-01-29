/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** error
*/

#include "main.h"

int error_init(sokoban_t *or, int argc, char **argv)
{
    if (argc != 2) {
        return (84);
    }
    return (0);
}

int error_middle(sokoban_t *or, int argc, char **argv)
{
    int i = 0;
    int count = 0;

    while (or->str[i] != '\0') {
        if (or->str[i] != 'P' && or->str[i] != '#' && or->str[i] != 'O'
        && or->str[i] != ' ' && or->str[i] != '\n' && or->str[i] != 'X') {
            count = count + 1;
        }
        i = i + 1;
    }
    if (count > 0 || or->size == 0) {
        return (84);
    }
    return (0);
}

void error_lenght(sokoban_t *or, int argc, char **argv)
{
    int a = 0;

    clear();
    while (1) {
        refresh();
        if (LINES < or->y || COLS < or->size_mal_max) {
            mvprintw(0, 0, "Terminal too small");
        } else {
            break;
        }
    }
}

int usage(sokoban_t *or, int argc, char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        write(1, "USAGE\n     ./my_sokoban map\nDESCRIPTION\n", 42);
        write(1, "     map  file representating the warehouse map, ", 50);
        write(1, "containing '#' for walls,\n          'P' for the ", 49);
        write(1, "player, 'X' for boxes and 'O' for storage locations.", 54);
        my_putchar('\n');
        return (84);
    }
    return (0);
}