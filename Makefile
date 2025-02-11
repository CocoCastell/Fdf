# Nom du programme
NAME = fdf

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
SRCS_DIR = srcs/
OBJS_DIR = objs/
MLX_DIR = mlx_linux/

# Fichiers source et objets
SRCS = main.c
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# Dépendances MiniLibX et Librairies nécessaires
MLX = $(MLX_DIR)libmlx.a
LIBS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# Options d'inclusion
INCLUDES = -I$(MLX_DIR) -Iincludes

# Fichiers de dépendances
DEPS = $(OBJS:.o=.d)

# Règles de compilation
all: $(NAME) Makefile

$(NAME): $(OBJS) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(OBJS_DIR)%.d
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR)


# Générer les fichiers de dépendances
$(OBJS_DIR)%.d: $(SRCS_DIR)%.c
	@$(CC) -MM $(CFLAGS) $(INCLUDES) $< > $@

-include $(DEPS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

