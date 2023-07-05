##
## EPITECH PROJECT, 2022
## Untitled (Workspace)
## File description:
## Makefile
##

NAME	= mysh

RM		= rm -f

SRCS	=  $(wildcard lib/*.c)	\
			$(wildcard src/*.c)

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -g

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -Wall $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
