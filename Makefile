# -*- MakeFile -*-

NAME=push_swap
FLAGS=-Werror -Wextra -Wall
SRC= src/big_sort.c src/helpers/checkers.c src/helpers/counters.c src/helpers/exit.c src/helpers/init.c src/main.c src/merge_sort.c src/operations/operation_cluster.c src/operations/operations.c src/helpers/push_swap_utils.c src/small_sort.c
INCLUDES=libft/libft.a

all: $(NAME_SERVER) $(NAME_CLIENT)
	@make -C libft/ bonus
	gcc $(FLAGS) $(SRC) $(INCLUDES) -o $(NAME)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all