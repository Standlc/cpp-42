NAME = classType

SOURCES = main.cpp Base.cpp

OBJECTS = $(SOURCES:.cpp=.o)

DEPENDENCIES = Makefile Base.hpp A.hpp B.hpp C.hpp

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