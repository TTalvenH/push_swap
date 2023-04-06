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
LIBFT = libft.a


all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(OBJ) -o $@
	
-include $(DEP)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean: 	clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all 
