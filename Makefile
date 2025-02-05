NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g
SANFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-omit-frame-pointer
MLXFLAGS = -lXext -lX11 -lm
MLX = minilibx-linux/libmlx.a
LIBFT = Libft/libft.a
PRINTF = Printf/libftprintf.a
SRCS = so_long.c errors.c validation.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX):
	@make -C minilibx-linux

$(LIBFT):
	@make -C Libft

$(PRINTF):
	@make -C Printf

$(NAME): $(OBJS) $(MLX) $(PRINTF) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(MLX) $(PRINTF) $(LIBFT) $(MLXFLAGS) -o $(NAME)
 
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@rm -rf *.o Libft/*.o Printf/*.o

fclean: clean
	@rm -rf $(NAME)
	@echo ALL CLEAR

re: fclean all