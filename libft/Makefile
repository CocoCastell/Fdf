# Variables

NAME		=	libft.a
CFLAGS		=	-Werror -Wextra -Wall
INC		= 	includes/

GNL_SRCS	=	gnl/get_next_line_bonus.c \
			gnl/get_next_line_utils_bonus.c
PRINTF_SRCS	=	printf/ft_manager_bonus.c \
			printf/ft_printf_bonus.c \
			printf/ft_types_bonus.c
LIBFT_SRCS	=	lib/ft_free_matrix.c \
			lib/ft_free_string_array.c \
			lib/ft_putnbr_fd.c \
			lib/ft_strmapi.c \
			lib/ft_putstr_fd.c \
			lib/ft_strncmp.c \
			lib/ft_atoi.c \
			lib/ft_itoa.c \
			lib/ft_split.c \
			lib/ft_strnstr.c \
			lib/ft_bzero.c \
			lib/ft_memchr.c \
			lib/ft_strchr.c \
			lib/ft_strrchr.c \
			lib/ft_calloc.c \
			lib/ft_memcmp.c \
			lib/ft_strrev.c \
			lib/ft_strdup.c \
			lib/ft_strtrim.c \
			lib/ft_isalnum.c \
			lib/ft_memcpy.c \
			lib/ft_striteri.c \
			lib/ft_substr.c \
			lib/ft_isalpha.c \
			lib/ft_memmove.c \
			lib/ft_strjoin.c \
			lib/ft_tolower.c \
			lib/ft_isascii.c \
			lib/ft_memset.c \
			lib/ft_strlcat.c \
			lib/ft_toupper.c \
			lib/ft_isdigit.c \
			lib/ft_putchar_fd.c \
			lib/ft_strlcpy.c \
			lib/ft_isprint.c \
			lib/ft_putendl_fd.c \
			lib/ft_strlen.c \
			lib/ft_lstadd_back_bonus.c \
			lib/ft_lstadd_front_bonus.c \
			lib/ft_lstclear_bonus.c \
			lib/ft_lstdelone_bonus.c \
			lib/ft_lstiter_bonus.c \
			lib/ft_lstlast_bonus.c \
			lib/ft_lstmap_bonus.c \
			lib/ft_lstnew_bonus.c \
			lib/ft_lstsize_bonus.c

OBJS_DIR	=	objs/
SRC		=	$(GNL_SRCS) $(PRINTF_SRCS) $(LIBFT_SRCS)
OBJ		=	$(SRC:%.c=$(OBJS_DIR)%.o)

# Colors

DEF_COLOR 	= 	\033[0m
GRAY		= 	\033[0;90m
RED			= 	\033[0;91m
GREEN		= 	\033[0;92m
YELLOW		= 	\033[0;93m
BLUE		= 	\033[0;94m
MAGENTA		= 	\033[0;95m
CYAN		= 	\033[0;96m
WHITE		= 	\033[0;97m


# Rules

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar -rcs $@ $^

$(OBJS_DIR)%.o:%.c	$(INC) Makefile
	@mkdir -p $(dir $@)
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
