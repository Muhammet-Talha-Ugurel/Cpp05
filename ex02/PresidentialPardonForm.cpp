#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm() {
  throw std::invalid_argument( "PresidentialPardonForm: default constructor is not allowed" );
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) :
    AForm( "Presidential Pardon Form", 25, 5 ), _target( target ) {
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &copy ) :
    AForm( copy ), _target( copy._target ) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &assign ) {
  if ( this != &assign ) {
    AForm::operator=( assign );
  }
  return *this;
}

void PresidentialPardonForm::execute( const Bureaucrat &executor ) const {
  if ( getGradeToExecute() < executor.getGrade() )
    throw AForm::GradeTooLowException();
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
