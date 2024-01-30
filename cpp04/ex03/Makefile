NAME		=	materia

SOURCES		=	main.cpp AMateria.cpp Ice.cpp Cure.cpp MateriaSource.cpp Character.cpp

OBJECTS		= 	$(SOURCES:.cpp=.o)

DEPENDENCIES	=	Makefile AMateria.hpp Ice.hpp Cure.hpp IMateriaSource.hpp MateriaSource.hpp Character.hpp ICharacter.hpp

RM			=	rm -f

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(OBJECTS) -o $(NAME)

%.o: %.cpp ${DEPENDENCIES}
	${CC} ${CFLAGS} -c $< -o $@

clean:
		@$(RM) $(OBJECTS)

fclean:	clean
		@$(RM) $(NAME)

re : fclean all

.PHONY : all re fclean clean