##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

all:
	make -sC ./asm

clean:
	make -sC ./asm clean

fclean: clean
	make -sC ./asm fclean

re: fclean all
