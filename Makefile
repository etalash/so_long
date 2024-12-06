CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/display.c \
		$(SRC_DIR)/movements.c $(SRC_DIR)/valid_map.c $(SRC_DIR)/flood_fill.c $(SRC_DIR)/map_init.c
OBJ = $(SRCS:.c=.o)

MLX_HEADER = lib/MLX42/include/MLX42
MLX_LIB = lib/MLX42/build

LIBFT_DIR = lib/libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

FT_PRINTF_DIR = lib/ft_printf
FT_PRINTF_NAME = libftprintf.a
FT_PRINTF = $(FT_PRINTF_DIR)/$(FT_PRINTF_NAME)

all: $(NAME) $(LIBFT) $(FT_PRINTF)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -I $(MLX_HEADER) -L $(MLX_LIB) -lmlx42 -lglfw -pthread -lm -o $(NAME)

mlx :
	cd lib && git clone https://github.com/ashirzad313/MLX42.git

clean_mlx :
	rm -rf lib/MLX42

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

fclean:
	rm -f $(OBJ) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all mlx, mlx_clean clean fclean re



