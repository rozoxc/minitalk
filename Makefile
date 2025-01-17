CC = cc
FLAGS = -Wall -Werror -Wextra
HEADER = minitalk.h

UTILS_SRC = utils/ft_atoi.c \
    utils/Convert_hex.c \
    utils/ft_printf.c \
    utils/ft_putnbr.c \
    utils/ft_strlen.c \
    utils/print_address.c \
    utils/ft_putchar.c \
    utils/ft_putstr.c \
    utils/hex.c \
    utils/unsigned.c

CLIENT_SRC = client.c
SERVER_SRC = server.c

UTILS_OBJ = $(UTILS_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

NAME_CLIENT = client
NAME_SERVER = server

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(NAME_CLIENT)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(UTILS_OBJ)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re