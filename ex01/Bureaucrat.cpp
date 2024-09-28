#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>

// Canonic class

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy ) : _name( copy._name ), _grade( copy._grade ) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &assign ) {
  if ( this == &assign )
    return *this;
  _grade = assign._grade;
  return *this;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name( name ) {
  if ( grade < 1 )
    throw GradeTooHighException();
  else if ( grade > 150 )
    throw GradeTooLowException();
  _grade = grade;
}

const std::string &Bureaucrat::getName() const {
  return _name;
}

int Bureaucrat::getGrade() const {
  return _grade;
}

void Bureaucrat::incrementGrade() {
  if ( _grade == 1 )
    throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if ( _grade == 150 )
	throw GradeTooLowException();
  _grade++;
}

void Bureaucrat::signForm( Form &form ) {
	try {
		form.beSigned( *this );
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	} catch ( std::exception &e ) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what()
			<< std::endl;
	}
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &bureaucrat ) {
  out << "Bureaucrat " << bureaucrat.getName() << " has grade "
      << bureaucrat.getGrade();
  return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}
