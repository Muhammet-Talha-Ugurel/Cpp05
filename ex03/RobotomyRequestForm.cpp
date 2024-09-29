#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm( "RobotomyRequestForm", 72, 45 ), _target( "default" ) {
	std::cout << "RobotomyRequestForm " << this->getTarget() << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &copy ) : AForm( copy ), _target( copy._target ) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm " << this->getTarget() << " destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &assign ) {
	if ( this == &assign )
		return *this;
	_target = assign._target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : AForm( "RobotomyRequestForm", 72, 45 ), _target( target ) {
}

std::string RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::execute( const Bureaucrat &executor ) const {
	if ( getGradeToExecute() < executor.getGrade() )
		throw AForm::GradeTooLowException();
	std::cout << "Drilling noises" << std::endl;
	if ( rand() % 2 )
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}
