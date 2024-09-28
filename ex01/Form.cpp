#include "Form.hpp"
#include <iostream>

// Canonical form

Form::Form() : _name( "default" ), _signed( false ), _gradeToSign( 1 ), _gradeToExecute( 1 ) {
}

Form::Form( const Form &copy ) : _name( copy._name ), _signed( copy._signed ), _gradeToSign( copy._gradeToSign ), _gradeToExecute( copy._gradeToExecute ) {
}

Form::~Form() {
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

Form &Form::operator=( const Form &assign ) {
	if ( this == &assign )
		return *this;
	_signed = assign._signed;
	return *this;
}

// Custom form

Form::Form( const std::string name, int gradeToSign, int gradeToExecute ) : _name( name ), _signed( false ), _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExecute ) { 
	if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
		throw Form::GradeTooHighException();
	if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
		throw Form::GradeTooLowException();
}

const std::string &Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (_signed)
		throw Form::AlreadySignedException();
	else if ( bureaucrat.getGrade() <= this->getGradeToSign() ) {
		_signed = true;	
	}
	else
		throw Form::GradeTooLowException();
} 

const char * Form::GradeTooHighException::what() const throw(){
	return ("Grade is too high!"); 
}

const char * Form::GradeTooLowException::what() const throw(){
	return ("Grade is too low!"); 
}

const char * Form::AlreadySignedException::what() const throw(){
	return ("Already Signed!"); 
}

std::ostream &operator<<( std::ostream &out, const Form &form ) {
	out	<< form.getName() << " Form Info.\n"
		<< "Is signed: " << (form.getSigned() ? "Yes" : "No") << ".\n"
		<< "Grade to sign: " << form.getGradeToSign() << ".\n"
		<< "Grade to execute: " << form.getGradeToExecute() << "." << std::endl;
	return out;
}
