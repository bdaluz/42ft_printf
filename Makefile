NAME        := libftprintf.a
CFLAGS      := -Wall -Wextra -Werror
RM          := rm -rf
AR          := ar -rcs

LIBFT_DIR   := includes/libft
LIBFT       := $(LIBFT_DIR)/libft.a

SRCS        := ft_printf.c
OBJS        := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(AR) $(NAME) $(LIBFT_DIR)/*.o

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) norminette.log

re: fclean all

.PHONY: all clean fclean re