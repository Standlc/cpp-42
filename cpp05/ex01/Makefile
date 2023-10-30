NAME = forms

SRCS = main.cpp Form.cpp Bureaucrat.cpp

OBJECTS = $(SRCS:.cpp=.o)

DEPENDENCIES = Makefile Form.hpp Bureaucrat.hpp

RM = rm -rf

FLAGS = -Wall -Wextra -Werror -std=c++98

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