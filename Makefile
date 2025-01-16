CC = cc
FLAGS = -Wall -Werror -Wextra
HEADER = minitalk.h
CLIENT_SRC = client.c \
			utils/ft_atoi.c \
			utils/Convert_hex.c \
			utils/ft_printf.c \
			utils/ft_putnbr.c \
			utils/ft_strlen.c \
			utils/print_address.c \
			utils/ft_putchar.c \
			utils/ft_putstr.c \
			utils/hex.c \
			utils/unsigned.c \

SERVER_SRC = server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

NAME_CLIENT = client
NAME_SERVER = server

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(NAME_CLIENT)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re

