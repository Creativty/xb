# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 15:37:44 by abderrahim        #+#    #+#              #
#    Updated: 2024/05/14 09:53:49 by aindjare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR		:=	ar
CC		:=	cc
NAME	:=	libxb.a
CFLAGS	:=	-Wall -Wextra -Werror $(CFLAGS_EX)
OBJECTS	:=	stack.o \
			stack_get.o \
			stack_pop.o \
			stack_node.o \
			stack_push.o \
			stack_debug.o \
			stack_lambda.o \
			stack_transform.o \
			strlen.o \
			strcmp.o \
			strcat.o \
			strcpy.o \
			strdup.o \
			strhas.o \
			strjoin.o \
			strpos.o \
			strslice.o \
			strsplit.o \
			arrlen.o \
			memset.o \
			free.o

all:	$(NAME)

$(NAME):	$(OBJECTS)
	$(AR) rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)
	rm -rf xb_tester

re:	fclean all

xb_tester:	xb_tests.c $(NAME)
	$(CC) $(CFLAGS) -g $^ -o $@

test:	xb_tester
	./xb_tester

.PHONY:	all clean fclean re test

.SECONDARY:	$(OBJECTS)
