NAME = btc

SRC = main.cpp BitcoinExchange.cpp

OBJ = ${SRC:.cpp=.o}

DEPENDENCIES = Makefile BitcoinExchange.hpp

RM = rm -rf

# FLAGS = -Wall -Werror -Wextra -std=c++98

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

.PHONY: all re fclean clean