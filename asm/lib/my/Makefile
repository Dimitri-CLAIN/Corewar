##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile lib
##

SRC		=		free_my_tab.c			\
				my_putchar.c			\
				my_putstr.c			\
				my_strcmp.c			\
				clean_str.c			\
				my_put_nbr.c			\
				my_getnbr.c			\
				str_to_word_array_n.c		\
				my_str_to_all_array.c		\
				my_clean_str_to_array.c		\
				my_strcat.c			\
				my_strlen.c			\
				my_strdup.c

OBJ	=			$(SRC:.c=.o)

NAME	=			libmy.a

all:				$(NAME)

$(NAME):			$(OBJ)
				ar rc $(NAME) $(OBJ)
				cp $(NAME) ../

clean:
				rm -f $(OBJ)

fclean:				clean
				rm -f $(NAME)
				rm -f ../$(NAME)

re:				fclean all
