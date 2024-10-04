CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
SRCS = check.c draw.c errors.c frees.c ft_strjoinfree.c key_hook.c main.c map_initialization.c map_validity.c window.c xpms_into_image.c
OBJ = $(SRCS:.c=.o)

MLX_HEADER = lib/MLX42/include/MLX42
MLX_LIB = lib/MLX42/build

LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

all: $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -I $(MLX_HEADER) -L $(MLX_LIB) -lmlx42 -lglfw -pthread -lm -o $(NAME)

mlx :
	git clone https://github.com/codam-coding-college/MLX42.git
	cmake -B build && cmake --build build -j4

clean_mlx :
	rm -rf lib/MLX42

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean:
	rm -f $(OBJ) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all mlx, mlx_clean clean fclean re
