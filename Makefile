NAME = push_swap

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_DIR = ./sources

SRC_FILES = operations.c \
            operations2.c \
            cheapest_cost.c \
            check_list.c \
            cost.c \
            ft_free.c \
            handel_list.c \
            handel_input.c \
            init_a_b.c \
            init_b_a.c \
            move_a_b.c \
            move_b_a.c \
            node_position.c \
            node_rank.c \
            sort_stack.c \
            target_node.c \
            push_swap.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC_OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) $(SRC_OBJS) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT_LIB):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

clean:
	@$(MAKE) --no-print-directory clean -C $(LIBFT_DIR)
	@$(RM) $(SRC_DIR)/*.o

fclean: clean
	@$(MAKE) --no-print-directory fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.SECONDARY: $(SRC_OBJS)

.PHONY: all clean fclean re
