NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src/
SRC = main.c swap.c push.c rotate.c rrotate.c
OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

all: libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) libft/*.o

libft:
	@make -C libft/

clean:
	@$(RM) $(OBJ)
	@make -C libft/ clean

fclean: clean
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re
