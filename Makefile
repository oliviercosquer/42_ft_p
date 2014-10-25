SERVER_NAME = server
CLIENT_NAME = client

INCLUDE_PATH = -I./include/ -I./lib/libft
LIBFT_DIR = ./lib/libft
LIB = -L$(LIBFT_DIR) -lft
FLAGS = -Wall -Werror -Wextra
SRC_PATH = ./src

SERVER_SRC_FILES =	main.c \
					ft_init.c
CLIENT_SRC_FILES =	main.c

SERVER_FILES = $(addprefix $(SRC_PATH)/server/,$(SERVER_SRC_FILES))
CLIENT_FILES = $(addprefix $(SRC_PATH)/client/,$(CLIENT_SRC_FILES))

all: libft_all server client

libft_all:
	@make -C $(LIBFT_DIR) all

libft_clean:
	@make -C $(LIBFT_DIR) clean

libft_fclean:
	@make -C $(LIBFT_DIR) fclean

libft_re:
	@make -C $(LIBFT_DIR) re

server:
	@echo Server compilation
	gcc $(OPTI) $(INCLUDE_PATH) $(LIB) $(FLAGS) $(SERVER_FILES) -o $(SERVER_NAME)
	@echo Server compilation done!

client: 
	@echo Client compilation
	gcc $(OPTI) $(INCLUDE_PATH) $(LIB) $(FLAGS) $(CLIENT_FILES) -o $(CLIENT_NAME)
	@echo Client compilation done!

clean: libft_clean
	@echo Delete .o files
	@rm -f $(SERVER_FILES:.c=.o)
	@rm -f $(CLIENT_SRC_FILES:.c=.o)
	@echo Delete done!

fclean: libft_fclean clean
	@echo Delete server $(SERVER_NAME)
	@rm -f $(SERVER_NAME)
	@echo Delete client $(CLIENT_NAME)
	@rm -f $(CLIENT_NAME)
	@echo Delete done!

re: libft_re fclean all