NAME = array

SRC = main.cpp

OBJ = ${SRC:.cpp=.o}

DEPENDENCIES = Makefile Array.hpp

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJ}
	c++ ${OBJ} -o ${NAME}

%.o: %.cpp ${DEPENDENCIES}
	c++ ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all re fclean clean