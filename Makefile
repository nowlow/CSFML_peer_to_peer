##
## EPITECH PROJECT, 2019
## Network
## File description:
## Makefile
##

SRC = 	make -C CLIENT	&& \
		make -C SERVER
all :
	make -C CLIENT && make -C SERVER

clean :
	make clean -C CLIENT && make clean -C SERVER

fclean :
	make fclean -C CLIENT && make fclean -C SERVER

re :	fclean all