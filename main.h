/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib/my/my.h"
#include <ncurses.h>

typedef struct pue
{
    int fd;
    char charac;
    char *str;
    char **tab;
    char **tab_stock;
    char **save;
    int i;
    int j;
    int k;
    int size;
    struct stat buf;
    int stock;
    int zoulou;
    int first_p;
    int second_p;
    int ch;
    char swap;
    int count_box;
    int count;
    int x;
    int y;
    int z;
    int size_mal;
    int size_mal_max;
    int test;
}sokoban_t;

void initialisation(sokoban_t *or, int argc, char **argv);
void double_tab(sokoban_t *or, int argc, char **argv);
int my_sokoban_second(sokoban_t *or);
void search_player_second(sokoban_t *or);
void search_player_first(sokoban_t *or);
void search_stock(sokoban_t *or);
void fonc_left_first(sokoban_t *or);
void fonc_left_second(sokoban_t *or);
void fonc_left_third(sokoban_t *or);
void fonc_left_main(sokoban_t *or);
void fonc_right_first(sokoban_t *or);
void fonc_right_second(sokoban_t *or);
void fonc_right_third(sokoban_t *or);
void fonc_right_four(sokoban_t *or);
void fonc_right_main(sokoban_t *or);
void fonc_low_first(sokoban_t *or);
void fonc_low_second(sokoban_t *or);
void fonc_low_third(sokoban_t *or);
void fonc_low_main(sokoban_t *or);
void fonc_top_first(sokoban_t *or);
void fonc_top_second(sokoban_t *or);
void fonc_top_third(sokoban_t *or);
void fonc_top_four(sokoban_t *or);
void fonc_top_main(sokoban_t *or);
int finish_first(sokoban_t *or);
void finish_second(sokoban_t *or);
int error_init(sokoban_t *or, int argc, char **argv);
int error_middle(sokoban_t *or, int argc, char **argv);
int usage(sokoban_t *or, int argc, char **argv);
void error_lenght(sokoban_t *or, int argc, char **argv);
void define_malloc_first(sokoban_t *or);
void define_malloc_second(sokoban_t *or);
int my_sokoban_first(sokoban_t *or, int argc, char **argv);
int error_final(sokoban_t *or);
int event(sokoban_t *or);

#endif /* !MAIN_H_ */
