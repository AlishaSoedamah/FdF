NAME = fdf
HEADER = -I ./includes -I $(PATH_LIBFT)/includes -I $(PATH_MLX)/include
CC = cc
CFLAGS = -MMD -fsanitize=address,undefined -O3 -Wall -Wextra -Werror -g3
SRC = fdf.c projection.c read_map.c check_file_name.c hooks.c line.c vector.c rotate.c zoom.c draw.c parse_map.c
SRC_DIR = src
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR = obj
DEP = $(OBJ:%.o=%.d)

LIB_DIR = libs
LIBFT = $(PATH_LIBFT)/libft.a
PATH_LIBFT = $(LIB_DIR)/libft
MLX = $(PATH_MLX)/build/libmlx42.a
PATH_MLX = $(LIB_DIR)/MLX42
LFLAGS = $(LIBFT) $(MLX) -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) $(LFLAGS) $(CFLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(MLX):
	@cmake $(PATH_MLX) -B $(PATH_MLX)/build && make -C $(PATH_MLX)/build -j4

$(LIBFT):
	@make -C $(PATH_LIBFT)
	
-include $(DEP)

clean:
	@echo "Cleaning objs"
	@ $(RM) -rf $(OBJ_DIR)
	@ $(RM) $(LIBMLX)/build
	@make -C $(PATH_LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
