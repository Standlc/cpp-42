NAME = scalar

SOURCES = main.cpp ScalarConverter.cpp

OBJECTS = $(SOURCES:.cpp=.o)

DEPENDENCIES = Makefile ScalarConverter.hpp

FLAGS = -Wextra -Wall -Werror -std=c++98

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ $(OBJECTS) -o $(NAME)

%.o: %.cpp $(DEPENDENCIES)
	c++ $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean