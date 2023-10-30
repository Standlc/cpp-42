NAME		=	zombies

SOURCES		=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJECTS		= 	$(SOURCES:.cpp=.o)

DEPENDECIES	=	Makefile

HEADERS		=	Zombie.hpp

RM			=	rm -f

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECTS) $(HEADERS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o : %.c $(DEPENDECIES) $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJECTS)

fclean:	clean
		@$(RM) $(NAME)

re : fclean all

.PHONY : all re fclean clean