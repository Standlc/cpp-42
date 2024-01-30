NAME		=	Fixed

SOURCES		=	main.cpp Fixed.cpp 

OBJECTS		= 	$(SOURCES:.cpp=.o)

DEPENDECIES	=	Makefile Fixed.hpp

RM			=	rm -f

CC			=	c++

CFLAGS		=	-Wall -Wextra -std=c++98 -Werror

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(OBJECTS) -o $(NAME)

%.o: %.cpp $(DEPENDECIES)
		cc $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJECTS)

fclean:	clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all re fclean clean