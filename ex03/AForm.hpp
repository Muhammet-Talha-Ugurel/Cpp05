#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
public: 
	AForm();
	AForm( const AForm &copy );
	~AForm();
	AForm &operator=( const AForm &assign );

	AForm( const std::string name, int gradeToSign, int gradeToExecute );
	const std::string &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned( const Bureaucrat &bureaucrat );
	virtual void execute( const Bureaucrat &executor ) const = 0;
	class GradeTooHighException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
	class AlreadySignedException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<( std::ostream &out, const AForm &form );
