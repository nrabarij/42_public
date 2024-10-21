# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrabarij <nrabarij@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:48:59 by nrabarij          #+#    #+#              #
#    Updated: 2024/02/25 13:14:37 by nrabarij         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ############################################################################ #
# ** CONSTANT_DEFINITION ***************************************************** #
# ############################################################################ #

NAME			=	libft.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f
CL				=	clear

SRC				=		\
					ft_atoi.c			\
					ft_bzero.c			\
					ft_calloc.c			\
					ft_isalnum.c		\
					ft_isalpha.c		\
					ft_isascii.c		\
					ft_isdigit.c		\
					ft_isprint.c		\
					ft_memchr.c			\
					ft_memcmp.c			\
					ft_memcpy.c			\
					ft_memmove.c		\
					ft_memset.c			\
					ft_strchr.c			\
					ft_strdup.c			\
					ft_strlcat.c		\
					ft_strlcpy.c		\
					ft_strlen.c			\
					ft_strncmp.c		\
					ft_strnstr.c		\
					ft_strrchr.c		\
					ft_tolower.c		\
					ft_toupper.c		\
					ft_itoa.c			\
					ft_putchar_fd.c		\
					ft_putendl_fd.c		\
					ft_putnbr_fd.c		\
					ft_putstr_fd.c		\
					ft_split.c			\
					ft_substr.c			\
					ft_striteri.c		\
					ft_strjoin.c		\
					ft_strmapi.c		\
					ft_strtrim.c

ALL				=	$(SRCS)

BIN				=	libft.a
SBIN			=	ft
INC				=	libft.h

DIRSRCS			=	.
DIROBJS			=	.
DIRBINS			=	.
DIRINCS			=	.
DIRMAIN			=	./main
DIRPROG			=	./prog

SRCS			=	$(addprefix $(DIRSRCS)/, $(SRC))
OBJS			=	$(SRCS:%.c=%.o)
BINS			=	$(addprefix $(DIRBINS)/,$(BIN))
INCS			=	$(addprefix $(DIRINCS)/,$(INC))
PRGS			=	$(ALL:%.c=%.$(EXT))
MAIN			=	$(SRCS:%.c=%_main.c)

%.o				:	%.c
					$(CC) $(CFLAGS) -I$(DIRINCS)/ -L$(DIRBINS)/ -c $< -o $@

$(NAME)			:	$(OBJS)
					ar rcs $(NAME) $(OBJS)
					ranlib $(NAME)

all				:	$(NAME)

clean			:
					$(RM) $(OBJS)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
