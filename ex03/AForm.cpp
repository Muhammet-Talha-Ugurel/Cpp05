#include "AForm.hpp"
#include <iostream>

// Canonical form

AForm::AForm() : _name( "default" ), _signed( false ), _gradeToSign( 1 ), _gradeToExecute( 1 ) {
}

AForm::AForm( const AForm &copy ) : _name( copy._name ), _signed( copy._signed ), _gradeToSign( copy._gradeToSign ), _gradeToExecute( copy._gradeToExecute ) {
}

AForm::~AForm() {
	std::cout << "AForm " << _name << " destroyed" << std::endl;
}

AForm &AForm::operator=( const AForm &assign ) {
	if ( this == &assign )
		return *this;
	_signed = assign._signed;
	return *this;
}

// Custom form

AForm::AForm( const std::string name, int gradeToSign, int gradeToExecute ) : _name( name ), _signed( false ), _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExecute ) { 
	if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
		throw AForm::GradeTooHighException();
	if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
		throw AForm::GradeTooLowException();
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (_signed)
		throw AForm::AlreadySignedException();
	else if ( bureaucrat.getGrade() <= this->getGradeToSign() ) {
		_signed = true;	
	}
	else
		throw AForm::GradeTooLowException();

} 

const char * AForm::GradeTooHighException::what() const throw(){
	return ("Grade is too high!"); 
}

const char * AForm::GradeTooLowException::what() const throw(){
	return ("Grade is too low!"); 
}

const char * AForm::AlreadySignedException::what() const throw(){
	return ("Already Signed!"); 
}

std::ostream &operator<<( std::ostream &out, const AForm &form ) {
	out	<< form.getName() << " AForm Info.\n"
		<< "Is signed: " << (form.getSigned() ? "Yes" : "No") << ".\n"
		<< "Grade to sign: " << form.getGradeToSign() << ".\n"
		<< "Grade to execute: " << form.getGradeToExecute() << "." << std::endl;
	return out;
}
