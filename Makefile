#.SILENT:

# Nom du programme
NAME = fdf

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

# Répertoires
SRCS_DIR = srcs/
OBJS_DIR = objs/
MLX_DIR = mlx_linux/
LIBFT_DIR = libft/

# Fichiers source et objets
SRCS = main.c error.c put_in_matrix.c
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
LIBFT_SRCS = 

# Dépendances MiniLibX et Librairies nécessaires
MLX = $(MLX_DIR)libmlx.a
LIBFT = $(LIBFT_DIR)libft.a
LIBS = $(LIBFT) -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz


# Options d'inclusion
INCLUDES = -I$(MLX_DIR) -Iincludes -I$(LIBFT_DIR)

# Fichiers de dépendances
DEPS = $(OBJS:.o=.d)

# Règles de compilation
all: $(NAME) 

$(NAME): $(OBJS) $(MLX) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	make --no-print-directory -C $(MLX_DIR)

$(LIBFT):
	make --no-print-directory -C $(LIBFT_DIR)

# Générer les fichiers de dépendances
#$(OBJS_DIR)%.d: $(SRCS_DIR)%.c 
#	$(CC) -MM $(CFLAGS) $(INCLUDES) $< > $@

-include $(DEPS)

clean:
	make clean --no-print-directory -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR) $(DEPS) 

fclean: clean
	make fclean --no-print-directory -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
