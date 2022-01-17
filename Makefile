CORE = ./srcs/operations/swap.c ./srcs/operations/push.c ./srcs/operations/rotate.c ./srcs/operations/rotate_2.c \
		./srcs/utils/ft_bzero.c ./srcs/print_error.c ./srcs/check.c ./srcs/utils/ft_atoi.c ./srcs/operations/stack_actions.c \
		./srcs/operations/stack_actions_2.c ./srcs/utils/ft_calloc.c ./srcs/utils/ft_strlen.c ./srcs/utils/is_in.c ./srcs/sort/sort.c \
		./srcs/sort/chunk.c ./srcs/sort/chunk_aux.c ./srcs/sort/default_sort.c ./srcs/sort/chunk_aux_2.c ./srcs/utils/ft_strncmp.c

SRCS =	./srcs/main.c $(CORE)

SRCS_CHECKER = ./srcs/checker.c ./srcs/utils/get_next_line.c $(CORE)

OBJS = $(SRCS:.c=.o)

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

NAME = push_swap

HEADER = ./includes/

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) -c -o $@ $< -I $(HEADER) $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -I $(HEADER) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(OBJS_CHECKER)
	$(CC) -I $(HEADER) $(CFLAGS) -o checker $(OBJS_CHECKER)

clean:
	$(RM) $(OBJS) $(OBJS_CHECKER)

fclean: clean
	$(RM) $(NAME) checker

re: fclean all

run: all
	valgrind ./$(NAME) 26 -16 -42 -39 -14 48 -41 20 10 -18 -12 40 -24 18 -30 -38 -4  1 34 -6 -46 -34 -7 42 14 -11 41 15 -15 11  2 -45 13 46 23 -19 37 49 -47 33 47 27 12  6 -5 -25 39 17 21 30 -31 -26 -1 -20 16 31 35 -8  8 -17 -37 -33 -35 19  3 -13 38 -28 -9 -48 -3 -29 43 -21  0 36 28 -27 22 -10 -36 -40  4 29 -2 25  9 45 24 -49  5 -23 -43 32 -50
	
.PHONY: clean fclean re all bonus