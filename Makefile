.SILENT:

NAME		=	fdf

# Compilation
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -MMD -MP

# Repository
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/
MLX_DIR		=	mlx_linux/
LIBFT_DIR	=	libft/

# Files
SRCS		=	main.c \
			error.c \
			map_init.c \
			draw_line.c \
			event_manager.c \
			isometry.c \
			color_mode.c \
			color.c \
			menu.c \
			utils.c
OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
LIBFT_FILES	=	gnl/get_next_line_bonus.c \
			gnl/get_next_line_utils_bonus.c \
			printf/ft_manager_bonus.c \
			printf/ft_printf_bonus.c \
			printf/ft_types_bonus.c \
			lib/ft_free_string_array.c \
			lib/ft_free_matrix.c \
			lib/ft_putnbr_fd.c \
			lib/ft_strmapi.c \
			lib/ft_putstr_fd.c \
			lib/ft_strncmp.c \
			lib/ft_atoi.c \
			lib/ft_split.c \
			lib/ft_strnstr.c \
			lib/ft_bzero.c \
			lib/ft_memchr.c \
			lib/ft_strchr.c \
			lib/ft_strrchr.c \
			lib/ft_calloc.c \
			lib/ft_memcmp.c \
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

LIBFT_SRCS	=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILES))

# Libraries
MLX		=	$(MLX_DIR)libmlx.a
LIBFT		=	$(LIBFT_DIR)libft.a
LIBS		=	$(LIBFT) -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# Includes
INCLUDES_PATH	=	-Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR)
INCLUDES	=	includes/fdf.h \
			$(MLX_DIR)mlx.h \
			$(MLX_DIR)mlx_int.h \
			$(LIBFT_DIR)includes/get_next_line_bonus.h \
			$(LIBFT_DIR)includes/ft_printf_bonus.h \
			$(LIBFT_DIR)includes/libft.h

# Dependencies
DEPS		=	$(LIBFT) $(LIBFT_SRCS) $(LIBFT_DIR) $(MLX) $(MLX_DIR) $(INCLUDES) $(LIBFT_DIR)includes $(LIBFT_DIR)gnl				 $(LIBFT_DIR)printf $(LIBFT_DIR)lib includes Makefile

# Rules
all:			$(NAME) 

$(NAME):		$(OBJS) $(DEPS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS_DIR)%.o:		$(SRCS_DIR)%.c
			mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) $(INCLUDES_PATH) -c $< -o $@

$(MLX):
			make --no-print-directory -C $(MLX_DIR)

$(LIBFT):
			make --no-print-directory -C $(LIBFT_DIR)

clean:
			make clean --no-print-directory -C $(LIBFT_DIR)
			rm -rf $(OBJS_DIR) 

fclean: 		clean
			make fclean --no-print-directory -C $(LIBFT_DIR)
			rm -f $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
