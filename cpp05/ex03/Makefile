NAME = bureau

SRCS =	main.cpp AForm.cpp \
		Bureaucrat.cpp PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp ShrubberyCreationForm.cpp \
		Intern.cpp

OBJECTS = $(SRCS:.cpp=.o)

DEPENDENCIES = 	Makefile AForm.hpp Bureaucrat.hpp \
				PresidentialPardonForm.hpp RobotomyRequestForm.hpp \
				ShrubberyCreationForm.hpp Intern.hpp

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