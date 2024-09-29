NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/mlx.a
INCLUDES = -I $(MLX_DIR)/includes

SRC = main.c
OBJ = $(SRC:.c=.o)

# Rules
all: $(MLX) $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(MLX_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
