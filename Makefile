NAME = fdf
CC = cc

all: $(NAME)

SRC_DIR = sources
OBJ_DIR = objects
FILES = main.c draw_points.c fdf.c points.c map.c hooks.c
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
INC = includes

OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
CFLAGS = -Wall -Werror -Wextra -g3 -I $(INC)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libraries/minilibx-linux/libmlx.a libraries/libft_full_library/libft.a -lXext -lX11 -lm -lz -ldl -lglfw -pthread -lm -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
re: fclean all

