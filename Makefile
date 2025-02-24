NAME = fdf
CC = cc

all: $(NAME)

SRC_DIR = sources
FILES = main.c
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
INC = includes

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g3 -I $(INC)
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libraries/minilibx-linux/libmlx.a libraries/libft_full_library/libft.a -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all

