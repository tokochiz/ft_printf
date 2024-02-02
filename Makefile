NAME = ft_printf.a
CC = cc
INC_DIR = includes
SRC_DIR = srcs
SRCFILES = $(SRC_DIR)/ft_printf.c \
		   $(SRC_DIR)/print_string.c

CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
SRCS = $(SRCFILES)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rem -f $(NAME)

re: fclean all

.PHONY: all clean fclean re