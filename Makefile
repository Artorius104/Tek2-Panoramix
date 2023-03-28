##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## 201yams
##

CC = gcc

CFLAGS 	+= -W -Wall -Wextra -g -lm

CFLAGS += -I./include

CFLAGS += -lpthread -lrt

CRITERION_FLAGS	=	--coverage -lcriterion

SRC		=	src/main.c	\
			src/check.c	\
			src/engine.c	\
			src/getArg.c	\
			src/druid.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	panoramix

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

.PHONY: clean fclean re all

RM:
	rm -f

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:		fclean all
