#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:21:22 by adebray           #+#    #+#              #
#    Updated: 2014/03/11 06:45:07 by gbir             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	lib2048.a
LIB			=	2048
HEADDIR		=	 ../../inc

SRC			=	array.c curse.c window.c up.c down.c right.c left.c init.c

OBJ			= $(subst .c,.o,$(SRC))

CC			= gcc
CCFLAGS		= -Werror -Wall -Wextra -Wuninitialized -I$(HEADDIR) -O3 -g

all: $(NAME)

<<<<<<< HEAD
$(NAME):	$(OBJ) $(HEADDIR)/game.h
=======
$(NAME):	$(OBJ)
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
			@ar rc $@ $^
			@ranlib $@
			@echo '!'
			@echo "\033[32m•\033[0m compil: \033[32m$(NAME)\033[0m"

<<<<<<< HEAD
%.o:		%.c $(HEADDIR)/game.h
=======
%.o:		%.c
>>>>>>> b931d671db4e2d2bb403367939b1b51c01d67ea7
			@echo '.''\c'
			@$(CC) $(CCFLAGS) -I $(HEADDIR) -o $@ -c $<

clean:
			@rm -f $(OBJ)
			@echo "\033[31m•\033[0m clean: \033[31m$(OBJ)\033[0m"

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[31m•\033[0m fclean: \033[31m$(NAME)\033[0m"

re:			fclean all

.PHONY: all clean fclean re
