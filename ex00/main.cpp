#include "Bureaucrat.hpp"
#include <cstddef>
#include <iostream>
#include <string>

Bureaucrat *tryNewBureaucrat( std::string name, int grade ) {
	try {
		std::cout << "Creating new Bureaucrat : " << name << " | grade : " << grade
			<< std::endl;
		Bureaucrat *res = new Bureaucrat( name, grade );
		std::cout << *res << std::endl;
		return res;
	} catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
	return NULL;
}

void tryDecrementGrade( Bureaucrat *b ) {
	try {
		std::cout << "Incrementing grade : " << b->getName()
			<< ", current grade is " << b->getGrade() << std::endl;
		b->decrementGrade();
		std::cout << "New grade : " << b->getGrade() << std::endl;
	} catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
}

void tryIncrementGrade( Bureaucrat *b ) {
	try {
		std::cout << "Incrementing grade of " << b->getName()
			<< ", current grade is " << b->getGrade() << std::endl;
		b->incrementGrade();
		std::cout << "New grade : " << b->getGrade() << std::endl;
	} catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
}

void tryDeleteBureaucrat( Bureaucrat *b ) {
	try {
		std::cout << "Deleting " << *b << std::endl;
		delete b;
	} catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
}

int main( void ) {
	Bureaucrat *arr[5] = {
		tryNewBureaucrat( "b1", 0 ), tryNewBureaucrat( "b2", 151 ),
		tryNewBureaucrat( "b3", 1 ), tryNewBureaucrat( "b4", 150 ),
		tryNewBureaucrat( "b5", 75 ) };

	std::cout << std::endl;

	for ( size_t i = 0; i < 5; i++ ) {
		if ( arr[i] ) {
			tryDecrementGrade( arr[i] );
			tryDecrementGrade( arr[i] );
			tryIncrementGrade( arr[i] );
			tryIncrementGrade( arr[i] );
			tryDeleteBureaucrat( arr[i] );
			std::cout << std::endl;
		}
	}
	return 0;
}
