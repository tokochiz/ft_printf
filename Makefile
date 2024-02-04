NAME = libftprintf.a
CC = cc
INC_DIR = includes
SRC_DIR = srcs
SRCFILES = ft_printf.c \
		   print_string.c\
		   print_hex.c \
		   ft_itoa.c

CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

SRCS = $(addprefix $(SRC_DIR)/, $(SRCFILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re