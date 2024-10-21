# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 22:05:14 by nrabarij          #+#    #+#              #
#    Updated: 2024/07/11 20:00:12 by nrabarij         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

BIN				=	libphilo.a

CC				=	cc

CFLAG			=	-Wall -Wextra -Werror -pthread

DIRSRC			=	./src

DIROBJ			=	./tmp

DIRBIN			=	./lib

MAIN			=	$(DIRSRC)/philo.c

SRC				=	phl_error.c phl_utils.c phl_mutex.c phl_action.c phl_check.c \

SRCS			=	$(addprefix $(DIRSRC)/, $(SRC))

OBJ				=	$(SRC:%.c=%.o)

OBJS			=	$(addprefix $(DIROBJ)/, $(OBJ))

LIB				=	$(addprefix $(DIRBIN)/, $(BIN))

LINK			=	-L $(DIRBIN) -lphilo

$(NAME)			:	$(LIB)
					$(CC) $(CFLAG) $(MAIN) $(LINK) -o $(NAME)

$(LIB)			:	$(OBJS)
					@mkdir -p $(DIRBIN)
					@ar rcs $(LIB) $(OBJS)

$(DIROBJ)/%.o	:	$(DIRSRC)/%.c
					@mkdir -p $(DIROBJ)
					$(CC) $(CFLAG) -c $< -o $@

all				:	$(NAME)

clean			:
					rm -rf $(DIROBJ)

fclean			:	clean
					rm -rf $(DIRBIN)
					rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
