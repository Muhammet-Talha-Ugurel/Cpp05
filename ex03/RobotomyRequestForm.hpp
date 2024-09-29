#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		// Canonical form
		RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm &copy );
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=( const RobotomyRequestForm &assign );
		// Custom form
		RobotomyRequestForm( const std::string target );
		std::string getTarget() const;
		void execute( const Bureaucrat &executor ) const;
};
