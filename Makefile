##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile
##

SRC_FOLDER 	=		asm/src/

SRC_FILE	=		add_char.c	\
				my_itohex.c	\
				read_my_file.c	\
				command_to_hexa.c\
				correct_size.c	\
				check_file.c	\
				get_inst.c	\
				create_my_bin.c

SRC		=		$(addprefix $(SRC_FOLDER), $(SRC_FILE))

MAIN_FILE	=		main.c

MAIN		=		$(addprefix $(SRC_FOLDER), $(MAIN_FILE))

TEST_FOLDER	=		asm/tests/

TEST_FILE	=		tests_my_algo.c

TEST		=		$(addprefix $(TEST_FOLDER), $(TEST_FILE))

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

NAME		=		asm/asm

BIN		=		unit_tests

CC		=		gcc

CFLAGS		=		-Iasm/include -g -W -Wall -Wextra

LIB		=		-Lasm/lib -lmy

LDFLAGS		=		-lcriterion --coverage

all:				$(NAME)

$(NAME):			$(OBJ)
				make -sC asm/lib/my
				$(CC) -o $(NAME) $(OBJ) $(LIB)

tests_run:
				make -sC asm/lib/my
		$(CC) -o $(BIN) $(SRC) $(TEST) $(CFLAGS) $(LIB) $(LDFLAGS)
				./$(BIN)

clean:
			make -sC asm/lib/my clean
			rm -f $(OBJ)
			rm -f *.gc*

fclean:			clean
			make -sC asm/lib/my fclean
			rm -f $(NAME)
			rm -f $(BIN)

re:			fclean all

.PHONY: all re clean fclean tests_run
