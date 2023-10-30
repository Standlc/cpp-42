NAME		=	ClapTrap

SOURCES		=	main.cpp ClapTrap.cpp

OBJECTS		= 	$(SOURCES:.cpp=.o)

DEPENDECIES	=	Makefile

RM			=	rm -f

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o : %.cpp $(DEPENDECIES) $(HEADERS)
		cc $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJECTS)

fclean:	clean
		@$(RM) $(NAME)

re : fclean all

.PHONY : all re fclean clean