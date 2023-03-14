NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
VPATH = src:src/operations
SRC = push_swap.c parse_int.c push_swap_utils.c push.c rotate.c reverse_rotate.c swap.c sort.c
OBJ_DIR = obj
OBJ =$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT = libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Ilibft -Llibft -lft -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -g -I./include -I./libft/include -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean: 	clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all 
