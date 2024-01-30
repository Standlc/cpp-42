NAME		=	pointers

SOURCES		=	main.cpp

OBJECTS		= 	$(SOURCES:.cpp=.o)

DEPENDENCIES	=	Makefile

RM			=	rm -f

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(OBJECTS) -o $(NAME)

%.o: %.cpp $(DEPENDENCIES)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJECTS)

fclean:	clean
		@$(RM) $(NAME)

re : fclean all

.PHONY : all re fclean clean