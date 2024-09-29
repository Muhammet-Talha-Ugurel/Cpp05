#pragma once

#include <iostream>

class Bureaucrat {
private:
	const std::string  _name;
	int _grade;
public:
	// Canonical form
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);
	// Custom form
	Bureaucrat(std::string name, int grade);
	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm( class AForm &form );
	void executeForm( class AForm &form );
	class GradeTooHighException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &bureaucrat );
