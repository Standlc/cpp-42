NAME		=	animals

SOURCES		=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJECTS		= 	$(SOURCES:.cpp=.o)

DEPENDECIES	=	Makefile Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

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