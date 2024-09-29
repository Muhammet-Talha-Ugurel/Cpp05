#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::Intern( const Intern &src ) {
  *this = src;
}

Intern::~Intern() {
}

Intern &Intern::operator=( const Intern &src ) {
  ( void ) src;
  return *this;
}

const std::string formNames[3][4] = {
    { "robotomy", "robotomy request", "robotomy request form", "robotomyrequestform" },
    { "presidential", "presidential pardon", "presidential pardon form", "presidentialpardonform" },
    { "shrubbery", "shrubbery creation", "shrubbery creation form", "shrubberycreationform" } };

AForm *Intern::makeForm( const std::string name, std::string target ) {
  for ( int i = 0; i < 3; i++ ) {
    for ( int j = 0; j < 4; j++ ) {
      if ( !name.compare( formNames[i][j] ) ) {
        switch ( i ) {
          case 0:
            std::cout << "Intern creates RobotomyRequestForm" << std::endl;
            return new RobotomyRequestForm( target );
          case 1:
            std::cout << "Intern creates PresidentialPardonForm" << std::endl;
            return new PresidentialPardonForm( target );
          case 2:
            std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
            return new ShrubberyCreationForm( target );
        }
      }
    }
  }
  std::cout << "Intern cannot create " << name << std::endl;
  throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "Form not found";
}
