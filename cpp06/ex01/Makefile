NAME = serializer

SOURCES = main.cpp Serializer.cpp

OBJECTS = $(SOURCES:.cpp=.o)

DEPENDENCIES = Makefile Serializer.hpp

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