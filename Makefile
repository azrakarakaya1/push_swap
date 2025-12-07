NAME = push_swap
FLAG = -Wall -Wextra -Werror

SRC = init.c main.c push.c radix.c reverse_rotate.c rotate.c simple_sort.c stack_utils.c swap.c utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAG) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re