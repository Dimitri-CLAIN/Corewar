##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile
##

SRC_FOLDER 	=		src/

SRC_FILE	=		add_char.c	\
				my_itoa.c	\
				my_itohex.c	\
				read_my_file.c	\
				command_to_hexa.c\
				correct_size.c	\
				check_file.c	\
				get_inst.c	\
				create_my_bin.c	\
				big_endian.c	\
				op.c		\
				get_arg.c	\
				inst_checker.c	\
				take_cmd.c	\
				give_name.c	\
				prepare_label_indexe.c	\
				check_arg.c			\
				get_inst_two.c		\
				val_check.c			\
				inst_checker_two.c		\
				sv_cmd.c

SRC		=		$(addprefix $(SRC_FOLDER), $(SRC_FILE))

MAIN_FILE	=		main.c

MAIN		=		$(addprefix $(SRC_FOLDER), $(MAIN_FILE))

TEST_FOLDER	=		tests/

TEST_FILE	=		tests_my_algo.c

TEST		=		$(addprefix $(TEST_FOLDER), $(TEST_FILE))

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

NAME		=		asm

BIN		=		unit_tests

CC		=		gcc

CFLAGS		=		-I./include -g -W

LIB		=		-L./lib -lmy

LDFLAGS		=		-lcriterion --coverage

all:				$(NAME)

$(NAME):			$(OBJ)
				make -sC lib/my
				$(CC) -o $(NAME) $(OBJ) $(LIB)

tests_run:
				make -sC lib/my
		$(CC) -o $(BIN) $(SRC) $(TEST) $(CFLAGS) $(LIB) $(LDFLAGS)
				./$(BIN)

clean:
			make -sC lib/my clean
			rm -f $(OBJ)
			rm -f *.gc*

fclean:			clean
			make -sC lib/my fclean
			rm -f $(NAME)
			rm -f $(BIN)

re:			fclean all

.PHONY: all re clean fclean tests_run
