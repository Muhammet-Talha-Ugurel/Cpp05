#pragma once

#include <iostream>

class Bureaucrat {
	private:
		const std::string  _name;
		int _grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(Bureaucrat &bureaucrat);

};
