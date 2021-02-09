##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	hs.c \
		card_create.c \
		combat.c \
		create_minion.c \
		get_input_keyboard.c \
		get_input_keyboard2.c \
		my_itoa.c \

OBJS = $(SRCS:.c=.o)

NAME = hearstone

all : $(NAME)

$(NAME) :
	gcc -g -o $(NAME) $(SRCS) -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -I include

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all