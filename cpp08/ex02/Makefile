NAME = mutantStack

SRC = main.cpp

OBJ = ${SRC:.cpp=.o}

DEPENDENCIES = Makefile MutantStack.hpp

RM = rm -rf

FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${OBJ}
	c++ ${OBJ} -o ${NAME}

%.o: %.cpp ${DEPENDENCIES}
	c++ ${FLAGS} -c $< -o $@

clean: 
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re