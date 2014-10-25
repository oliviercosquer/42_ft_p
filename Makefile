SERVER_NAME = server
CLIENT_NAME = client

INCLUDE_PATH = -I./include/ -I./lib/libft/includes
LIBFT_DIR = ./lib/libft
LIB = -L$(LIBFT_DIR) -lft
FLAGS = -Wall -Werror -Wextra
SRC_PATH = ./src

SERVER_SRC_FILES =	main.c \
					ft_init.c \
					ft_prompt.c \
					ft_check_arg.c
CLIENT_SRC_FILES =	main.c
COMMON_SRC_FILES = 

SERVER_FILES = $(addprefix $(SRC_PATH)/server/,$(SERVER_SRC_FILES))
CLIENT_FILES = $(addprefix $(SRC_PATH)/client/,$(CLIENT_SRC_FILES))
COMMON_FILES = $(addprefix $(SRC_PATH)/common/,$(COMMON_SRC_FILES))

all: libft_all server client

libft_all:
	@make -C $(LIBFT_DIR) all

libft_clean:
	@make -C $(LIBFT_DIR) clean

libft_fclean:
	@make -C $(LIBFT_DIR) fclean

server:
	@echo Server compilation
	gcc $(INCLUDE_PATH) $(FLAGS) $(COMMON_FILES) $(SERVER_FILES) -o $(SERVER_NAME) $(LIB) 

client: 
	@echo Client compilation
	gcc $(INCLUDE_PATH) $(FLAGS) $(COMMON_FILES) $(CLIENT_FILES) -o $(CLIENT_NAME) $(LIB) 

clean: libft_clean
	@echo Delete .o files
	@rm -f $(SERVER_FILES:.c=.o)
	@rm -f $(CLIENT_SRC_FILES:.c=.o)

fclean: libft_fclean clean
	@echo Delete server $(SERVER_NAME)
	@rm -f $(SERVER_NAME)
	@echo Delete client $(CLIENT_NAME)
	@rm -f $(CLIENT_NAME)

re: fclean all