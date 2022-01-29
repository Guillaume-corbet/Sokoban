##
## EPITECH PROJECT, 2018
## Evalexpr
## File description:
## Makefile
##

SRC		=	./main.c		\
			./left.c		\
			./right.c		\
			./low.c		\
			./top.c		\
			./init.c		\
			./error.c		\
			./malloc.c		\
			./other.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	clean fclean $(NAME)

$(NAME):
		(cd ./lib/my/ && make)
		gcc -o $(NAME) $(SRC) -Llib/my/. -lmy -lncurses

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:
		fclean $(NAME)

auteur:
		echo $(USER) > auteur
