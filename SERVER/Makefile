##
## EPITECH PROJECT, 2018
## SERVER
## File description:
## Makefile
##

SRC = 	./src/network.c

NAME = 	network

OBJ = $(SRC:.c=.o)

all :	$(NAME)

CSFML = 	-lcsfml-system	\
			-lcsfml-network

$(NAME) :
	gcc -o $(NAME) $(SRC) $(CSFML)

clean :
	rm -f $(OBJ)

fclean : 	clean
	rm -f $(NAME)

re : 		fclean all