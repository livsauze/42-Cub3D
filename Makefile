# ***********Color Definition************#
RED = \033[91m
YELLOW = \033[33m
GREEN = \033[92m
#****************************************#

NAME = cub3D

LINK = -Llibft -lft -lXext -lX11 -lm

MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)
INC =   -I ./include/\
				-I ./libft/\

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

SRCS_DIR = src
SRCS =  $(wildcard $(SRCS_DIR)/*.c) \
		$(wildcard $(SRCS_DIR)/utils/*.c) \
		$(wildcard $(SRCS_DIR)/parsing/*.c) \
		$(wildcard $(SRCS_DIR)/init/*.c) \
		$(wildcard $(SRCS_DIR)/ray_casting/*.c) \
		$(wildcard $(SRCS_DIR)/minimap/*.c) 
OBJS_DIR := obj
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))


all : $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@


$(NAME) : $(OBJS)
	@echo "$(YELLOW)...Compiling...\n"
	@make -sC $(MLX_PATH)
	@make -C libft/
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(MLX) $(LINK) -o $(NAME)
	@echo "$(GREEN) Compilation OK ✅"


clean :
	@rm -rf $(OBJS_DIR)
	@make clean -C libft/
	@make -C $(MLX_PATH) clean
	@echo "$(RED)Deleting object files\n"


fclean : clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "$(RED)Deleting executable\n"

re : fclean all

.PHONY : all clean fclean re