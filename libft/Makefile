# Variables

NAME = libft.a
CFLAGS = -Werror -Wextra -Wall
INC = ./libft_b/includes/libft.h ./gnl_b/includes/get_next_line_bonus.h ./ft_printf_b/includes/ft_printf_bonus.h

GNL_SRCS = $(wildcard ./gnl_b/src/*.c)
PRINTF_SRCS = $(wildcard ./ft_printf_b/src/*.c)
LIBFT_SRCS = $(wildcard ./libft_b/src/*.c)

SRC = $(GNL_SRCS) $(PRINTF_SRCS) $(LIBFT_SRCS)
OBJ = $(SRC:%.c=%.o)

# Colors

DEF_COLOR = \033[0m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


# Rules

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $^

%.o:%.c	$(INC) Makefile
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
