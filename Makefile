# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 15:29:20 by tdausque          #+#    #+#              #
#    Updated: 2025/01/05 10:13:47 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files
SERVER = server.c
CLIENT = client.c
PRINTF = ft_printf/libftprintf.a
LIBFT = lib/libft.a

# Sources and objects
SERVER_SRC = $(SERVER)
SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_SRC = $(CLIENT)
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
OBJS = $(CLIENT_OBJS) \ $(SERVER_OBJS)

# ------------------------------ Constant strings ------------------------------

CC = cc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
INCLUDE = -I include
SERVER_NAME = server
CLIENT_NAME = client
NAME = minitalk

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"
SERV_READY	=	echo "\n📥 Server ready!\n"
CLI_READY	=	echo "\n📟 Client ready!\n"
CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------

all: $(PRINTF) $(LIBFT) $(NAME)

$(NAME): comp_start server client

$(PRINTF):
	@cd ft_printf && make

$(LIBFT):
	@cd lib && make
	
comp_start:
	@$(COMP_START)

server: $(SERVER_OBJS)
	@$(CC) $(FLAGS) $(SERVER_OBJS) $(PRINTF) $(LIBFT) -o $(SERVER_NAME)
	@$(SERV_READY)

client: $(CLIENT_OBJS)
	@$(CC) $(FLAGS) $(CLIENT_OBJS) $(PRINTF) $(LIBFT) -o $(CLIENT_NAME)
	@$(CLI_READY)

clean:
	@rm -rf $(OBJS)
	@cd ft_printf && make clean
	@cd lib && make clean

fclean:
	@rm -rf *.o client server
	@cd ft_printf && make fclean
	@cd lib && make fclean
	@$(FCLEANED)

.c.o:
	@${CC} ${FLAGS} $(INCLUDE) -c $< -o $@
		
re: fclean all

.PHONY: all clean fclean re ft_printf
