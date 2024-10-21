# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 15:29:14 by nrabarij          #+#    #+#              #
#    Updated: 2024/06/01 12:26:20 by nrabarij         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constant definitions ******************************************************* #

NAME		=	fdf

RM			=	rm -rf

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

BOLD		=	"\033[1m"

GREEN		=	"\033[92m"

BLUE		=	"\033[96m"

RESET		=	"\033[0m"

# Directories and Binary definitions ***************************************** #

DIRFDF		=	.

FDF_A		=	libfdf.a

BINFDF		=	$(addprefix $(DIRFDF)/, $(FDF_A))

DIRLIBFT	=	./libft

LIBFT_A		=	libft.a

BINLIBFT	=	$(addprefix $(DIRLIBFT)/, $(LIBFT_A))

DIRMLX		=	./minilibx

MLX_A		=	libmlx.a

BINMLX		=	$(addprefix $(DIRMLX)/, $(MLX_A))

# Source and object files **************************************************** #

DIRSRC		=	./src

SRC			=	fdf_file.c fdf_init.c fdf_memo.c fdf_parse.c fdf_point.c\
				fdf_draw.c fdf_color.c fdf_image.c fdf_key.c\

SRCS		=	$(addprefix $(DIRSRC)/, $(SRC))

OBJS		=	$(SRCS:%.c=%.o)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

MAINFDF		=	$(DIRSRC)/fdf.c

# Rules ********************************************************************** #

INFO		=	$(BLUE)$(BOLD)configure$(RESET) [$(GREEN)info$(RESET)] :

LINKER		=	-L./ -lfdf -lft -lmlx -L -lmlx -lXext -lX11 -lm

$(NAME)		:	$(BINFDF) $(BINLIBFT) $(BINMLX) $(MAINFDF)
				@echo $(INFO) Execute \"make all\" from \"Makefile\"
				$(CC) $(CFLAGS) $(MAINFDF) $(LINKER) -o $(NAME)

$(BINFDF)	:	$(OBJS) $(BINLIBFT) $(BINMLX)
				@echo $(INFO) Execute \"make libfdf.a\" from \"Makefile\"
				ar rcs $(BINFDF) $(OBJS)

$(BINLIBFT)	:
				@echo $(INFO) Execute \"make all\" from \"libft/Makefile\"
				@make -C $(DIRLIBFT)/ all
				cp $(BINLIBFT) $(LIBFT_A)

$(BINMLX)	:
				@echo $(INFO) Execute \"make all\" from \"minilibx/Makefile\"
				@make -C $(DIRMLX)/ all
				cp $(BINMLX) $(MLX_A)

all			:	$(NAME)

clean		:
				@echo $(INFO) Execute \"make clean\" from \"libft/Makefile\"
				@make -C $(DIRLIBFT)/ clean
				@echo $(INFO) Execute \"make clean\" from \"Makefile\"
				$(RM) $(OBJS)

fclean		:	clean
				@echo $(INFO) Execute \"make clean\" from \"minilibx/Makefile\"
				@make -C $(DIRMLX)/ clean
				@echo $(INFO) Execute \"make fclean\" from \"libft/Makefile\"
				@make -C $(DIRLIBFT)/ fclean
				@echo $(INFO) Execute \"make fclean\" from \"Makefile\"
				$(RM) $(MLX_A)
				$(RM) $(LIBFT_A)
				$(RM) $(FDF_A)
				@echo $(INFO) Remove program \"./fdf\".
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
