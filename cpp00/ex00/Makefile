NAME		=	megaphone

SOURCES		=	megaphone.cpp \

OBJECTS		= 	$(SOURCES:.cpp=.o)

DEPENDECIES	=	Makefile

RM			=	rm -f

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECTS) $(DEPENDECIES)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
		@$(RM) $(OBJECTS)

fclean:	clean
		@$(RM) $(NAME)

re : fclean all

.PHONY : all re fclean clean