NAME		=	FragTrap

SOURCES		=	main.cpp ClapTrap.cpp FragTrap.cpp

OBJECTS		= 	$(SOURCES:.cpp=.o) 

DEPENDENCIES	=	Makefile ClapTrap.hpp FragTrap.hpp

RM			=	rm -f

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(OBJECTS) -o $(NAME)

%.o: %.cpp $(DEPENDENCIES)
		cc $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJECTS)

fclean:	clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all re fclean clean