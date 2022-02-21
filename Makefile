NAME = push_swap

SRCS =	functions/parse/init.c \
		functions/helper/tools.c \
		functions/helper/parse_checks.c \
		functions/helper/fivesort_checks.c \
		functions/sorting/operations.c \
		functions/sorting/order.c \
		push_swap.c

FLAGS = -Wall -Wextra -Werror

DEBUG_FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

OBJS = $(SRCS:.c=.o)

LIBFT= ./libft/libft.a

CC = gcc

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(LIBFT)

$(LIBFT):
	@make bonus -C ./libft/

norme:
	@norminette $(SRCS)

debug: $(NAME)
	$(CC) $(DEBUG_FLAGS) $(SRCS) -o $(NAME) $(LIBFT)

clean:
	@make clean -C ./libft/
	@rm -rf $(OBJS)
	@echo "cleaning .o files"

fclean: clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)

re: fclean all