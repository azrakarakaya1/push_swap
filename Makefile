NAME = push_swap
FLAG = -Wall -Wextra -Werror

SRC = 

OBJ = $(SRC:.c=o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAG) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

RE: fclean all

.PHONY: all clean fclean re