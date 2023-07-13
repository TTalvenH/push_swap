NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD
INCLUDE = -I./include -I./libft/include
VPATH = src:src/operations
SRC = main.c parse_int.c push_swap_utils.c push.c rotate.c reverse_rotate.c swap.c sort.c median.c
OBJ_DIR = obj
OBJ =$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEP =$(OBJ:.o=.d)

LIBFT_FLAGS = -Ilibft -Llibft -lft
LIBFT = libft/libft.a


all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) -o $@
	
-include $(DEP)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean: 	clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all 
