# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/02 03:26:29 by adebray           #+#    #+#              #
#    Updated: 2015/02/27 23:45:38 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	game_2048
HEADDIR			=	inc
HEADFLAG		=	-I ./$(HEADDIR)

SRCDIR			=	src
SRC				=	main.c
OBJ				=	$(subst .c,.o,$(SRC))

CC				=	gcc
CCFLAGS			=	-Werror -Wall -Wextra -Wuninitialized -O3

LIBLIBFT		=	-L$(SRCDIR)/libft -lft
LIBPRINTF		=	-L$(SRCDIR)/ft_printf -lftprintf
LIBESSENTIAL	=	$(LIBLIBFT) $(LIBPRINTF)

LIBNCURSES		=	$(LIBESSENTIAL) -lncurses
LIB2048			=	-L$(SRCDIR)/2048 -l2048

.PHONY: all clean fclean re

all: makelib $(NAME)

makelib: _libft _printf _2048

$(NAME): $(OBJ) $(HEADDIR)/game.h $(SRCDIR)/libft/libft.a $(SRCDIR)/ft_printf/libftprintf.a $(SRCDIR)/2048/lib2048.a
	@$(CC) $(CCFLAGS) $(HEADFLAG) -o $(NAME) $(SRC) $(LIBNCURSES) $(LIB2048)
	@echo '!'
	@echo "\033[32m•\033[0m $(NAME) compil: \033[32m$(NAME)\033[0m"

_libft: $(HEADDIR)/libft.h
	@make -C $(SRCDIR)/libft

_printf: $(HEADDIR)/ft_printf.h
	@make -C $(SRCDIR)/ft_printf

_2048: $(HEADDIR)/game.h
	@make -C $(SRCDIR)/2048

%.o: %.c
	@echo '.''\c'
	@$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	@make -C $(SRCDIR)/libft clean
	@make -C $(SRCDIR)/2048 clean
	@make -C $(SRCDIR)/ft_printf clean
	@rm -f $(OBJ)
	@echo "\033[31m•\033[0m $(NAME) clean.\033[0m"

fclean:
	@make -C $(SRCDIR)/libft fclean
	@make -C $(SRCDIR)/2048 fclean
	@make -C $(SRCDIR)/ft_printf fclean
	@rm -f $(OBJ)
	@rm -f $(LIBNAME)
	@rm -f $(NAME)
	@rm -f asm
	@echo "\033[31m•\033[0m $(NAME) fclean: \033[31m$(NAME)\033[0m"

re: fclean all
