NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = indexing.c  parsing.c  push.c  push_swap.c  rotate.c  rrotate.c  sort.c  swap.c  utils.c
OBJS        = $(SRCS:.c=.o)

LIBFT_LIB   = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C ./libft

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
