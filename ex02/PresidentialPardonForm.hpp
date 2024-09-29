#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
	const std::string _target;

  public:
	PresidentialPardonForm();
	PresidentialPardonForm( const std::string target );
	PresidentialPardonForm( const PresidentialPardonForm &copy );
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &operator=( const PresidentialPardonForm &assign );

	virtual void execute( const class Bureaucrat &executor ) const;
};
