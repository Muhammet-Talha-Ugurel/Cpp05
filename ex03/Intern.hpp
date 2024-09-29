#pragma once

#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();
		Intern& operator=(const Intern& src);

		AForm* makeForm(std::string name, std::string target);

		class FormNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
