#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public: 
		Form();
		Form( const Form &copy );
		~Form();
		Form &operator=( const Form &assign );

		Form( const std::string name, int gradeToSign, int gradeToExecute );
		const std::string &getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned( const Bureaucrat &bureaucrat );
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

std::ostream &operator<<( std::ostream &out, const Form &form );
