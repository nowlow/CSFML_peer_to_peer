##
## EPITECH PROJECT, 2018
## CLIENT
## File description:
## Makefile
##

SRC =	./src/client.c

NAME =	client

OBJ =	$(SRC:.c=.o)

CSFML =	-lcsfml-system	\
		-lcsfml-network

all :	$(NAME)

$(NAME) :
	gcc -o $(NAME) $(SRC) $(CSFML)

clean :
	rm -f $(OBJ)

fclean :	clean
	rm -f $(NAME)

re :	fclean all