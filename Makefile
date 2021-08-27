# -*- MakeFile -*-

NAME=push_swap
FLAGS=-Werror -Wextra -Wall
SRC=*.c
INCLUDES=libft/libft.a

all: $(NAME_SERVER) $(NAME_CLIENT)
	@make -C libft/ bonus
	gcc $(SRC) $(FLAGS) $(INCLUDES) -o $(NAME)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all