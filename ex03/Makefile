NAME = ex03

SRC		=	main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
			ShrubberyCreationForm.cpp \
			Intern.cpp

ifeq ($(shell uname), Linux)
	CC = clang++
else
	CC = c++
endif

CFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++98


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: clean all
