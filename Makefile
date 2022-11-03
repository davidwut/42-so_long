NAME		:= so_long

SRC_DIR		:= src
SRCS		:= $(wildcard $(SRC_DIR)/*.c)
OBJS		:= $(SRCS:%.c=%.o)

LIBFT_NAME	:= libft.a
LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/$(LIBFT_NAME)

MLIB		:= libmlx_Linux.a
MLX_DIR		:= mlx_linux
MLX			:= $(MLX_DIR)/$(MLIB)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
MLXFLAGS_C	:= -I/usr/include -Imlx_linux -O3
MLXFLAGS_EXE:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM			:= rm -f

all: 		$(MLX) $(LIBFT) $(NAME)

$(MLX):
			$(MAKE) -C $(MLX_DIR)

$(LIBFT):
			@$(MAKE) -C $(LIBFT_DIR)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $< $(MLXFLAGS_EXE) -o $@ $(LIBFT)

%.o:		%.c
			$(CC) $(CFLAGS) $(MLXFLAGS_C) -c $< -o $@

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
