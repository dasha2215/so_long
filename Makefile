NAME = so_long

SRC = src/main.c  src/error_handler.c src/parse_map.c \
src/initializer.c src/draw_sprites.c utils/get_next_line.c \
src/hooks.c src/draw_map.c utils/utils.c src/check_map.c \
src/load_images.c src/animation.c src/camera.c src/load_character.c
OBJ = $(SRC:.c=.o)
HEADER = includes/so_long.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf


MLX_DIR = MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_INCLUDE = -I$(MLX_DIR)/include
MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -L/opt/homebrew/lib -lglfw3 -ldl -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -pthread -lm

MYLIB_DIR = mylib
MYLIB = $(MYLIB_DIR)/mylib.a

all: $(NAME)

%.o: %.c $(HEADER) $(MLX_INCLUDE) Makefile
	$(CC) $(CFLAGS) $(MLX_INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(MYLIB) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) $(MYLIB)


$(MLX_LIB):
	@cmake -B $(MLX_DIR)/build $(MLX_DIR)
	@cmake --build $(MLX_DIR)/build

$(MYLIB):
	@make -C $(MYLIB_DIR)


clean:
	$(RM) $(OBJ)
	@make clean -C $(MYLIB_DIR)
	@cmake --build $(MLX_DIR)/build --target clean

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(MYLIB_DIR)
	$(RM) $(MLX_DIR)/build

re: fclean all

.PHONY: all clean fclean re
