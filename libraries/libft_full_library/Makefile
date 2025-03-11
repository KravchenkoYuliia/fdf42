# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukravch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 12:49:28 by yukravch          #+#    #+#              #
#    Updated: 2025/02/24 11:18:15 by yukravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = /usr/bin/cc
AR = /usr/bin/ar
RM = /usr/bin/rm
MKDIR = /usr/bin/mkdir

all: $(NAME)

PATH = sources
FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
                        ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
                        ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
                        ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
                        ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
                        ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
                        ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
                        ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
                        \
                        ft_printf.c ft_print_hexa_printf.c ft_putchar_printf.c ft_putnbr_printf.c \
                        ft_putstr_printf.c \
                        \
                        get_next_line.c get_next_line_utils.c
SRC = $(addprefix $(PATH)/, $(FILES))
OBJ_DIR = objects

INC = includes/

OBJECTS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
CFLAGS = -Wall -Wextra -Werror -I $(INC)

$(NAME): $(OBJ_DIR) $(OBJECTS)
	$(AR) rcs $(NAME) $(OBJECTS)

$(OBJ_DIR):
	$(MKDIR) -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
