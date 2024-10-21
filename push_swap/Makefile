# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 19:23:15 by nrabarij          #+#    #+#              #
#    Updated: 2024/04/30 10:42:29 by nrabarij         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
PROGBIN			=	libps.a
CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
BIN				=	libft.a
DIRBIN			=	./libft
BINPROG			=	-L./ -lps
LIBFT			=	$(addprefix $(DIRBIN)/, $(BIN))
RM				=	rm -rf
DIROBJ			=	./obj
DIRSRC			=	.
SRC				=	\
					push_swap.c\
					ps_error.c\
					ps_iter.c\
					ps_move.c\
					ps_three.c\
					ps_solve.c\
					ps_algo.c\
					ps_rotate.c\
					ps_sort.c\
					ps_chunk.c\
					ps_tgt.c\
					ps_src.c\
					ps_input.c\
					ps_move_common.c\

SRCS			=	$(addprefix $(DIRSRC)/, $(SRC))
OBJS			=	$(SRC:%.c=$(DIROBJ)/%.o)
MAIN			=	$(DIRSRC)/main.c
$(DIROBJ)/%.o	:	$(DIRSRC)/%.c
					$(CC) $(CFLAG) -I./ -c $< -o $@
$(NAME)			:	$(PROGBIN) $(LIBFT) $(SRCS) $(MAIN)
					$(CC) $(CFLAG) $(MAIN) $(BINPROG) -o $(NAME)
$(PROGBIN)		:	$(LIBFT) $(DIROBJ) $(OBJS)
					cp $(LIBFT) $(PROGBIN)
					ar rcs $(PROGBIN) $(OBJS)
$(LIBFT)		:
					make -C $(DIRBIN) all
$(DIROBJ)		:
					mkdir -p $(DIROBJ)
all				:	$(NAME)
clean			:
					make -C $(DIRBIN) clean
					$(RM) $(DIROBJ)
fclean			:	clean
					make -C $(DIRBIN) fclean
					$(RM) $(NAME) $(BONUS) $(PROGBIN)
re				:	fclean all
.PHONY			:	all clean fclean re
