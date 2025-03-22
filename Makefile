NAME = fdf
NAME_BONUS = fdf_bonus
LIBS = libraries/minilibx-linux/libmlx.a libraries/libft_full_library/libft.a
CC = cc

all: $(NAME)

SRC_DIR = sources
OBJ_DIR = objects
FILES = main.c draw_points.c fdf.c initialize.c calculation.c map.c hooks.c exit.c free.c
FILES_BONUS = main.c draw_points.c fdf.c initialize.c calculation.c map.c exit.c free.c hooks_bonus.c 
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
INC = includes

OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.o))
CFLAGS = -Wall -Werror -Wextra -g3 -I $(INC)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -I/opt/X11/include -I/opt -c $< -o $@

$(NAME_BONUS): $(OBJ_BONUS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) -lXext -lX11 -lm -lz -ldl -lglfw -pthread -lm -o $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -lXext -lX11 -lm -lz -ldl -lglfw -pthread -lm -o $(NAME)

$(LIBS):
	make -C libraries/minilibx-linux
	make -C libraries/libft_full_library

mac: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I/opt/X11/include -I/opt -L/opt/X11/lib -o $(NAME) -lX11

bonus: $(NAME_BONUS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
re: fclean all

