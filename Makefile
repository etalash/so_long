# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

# Executable name
NAME = so_long

# Directories (no src folder)
MLX_DIR = lib/minilibx-linux
LIBFT_DIR = lib/libft

# Sources and Objects (no src folder)
SRCS = main.c check.c draw.c errors.c frees.c ft_strjoinfree.c \
       key_hook.c map_validity.c window.c xpms_into_image.c
OBJ = $(SRCS:.c=.o)

# Libraries
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_HEADER = $(MLX_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

# Linking flags (for X11, pthread, and math library)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd -I$(MLX_HEADER)

# Default target
all: $(NAME)

# Build rule for object files (no src folder)
%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_HEADER) -c $< -o $@

# Build rule for the executable
$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Build libft if necessary
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build the minilibx-linux library
$(MLX_LIB):
	git clone git@github.com:42Paris/minilibx-linux.git $(MLX_DIR)
	make -C $(MLX_DIR)

# Clean object files and minilibx-linux
clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

# Full cleanup (objects and executable)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
