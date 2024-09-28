#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <cstddef>
#include <iostream>

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

void tryDeleteBureaucrat( Bureaucrat *b ) {
  try {
    std::cout << "Deleting " << *b << std::endl;
    delete b;
  } catch ( std::exception &e ) {
    std::cout << e.what() << std::endl;
  }
}

Form *tryNewForm( std::string name, int signGrade, int execGrade ) {
  try {
	std::cout << "Creating new Form : " << name << " | sign grade : " << signGrade
			  << " | exec grade : " << execGrade << std::endl;
	Form *res = new Form( name, signGrade, execGrade );
	std::cout << *res << std::endl;
	return res;
  } catch ( std::exception &e ) {
	std::cout << e.what() << std::endl;
  }
  return NULL;
}

void tryDeleteForm( Form *f ) {
  try {
	std::cout << "Deleting " << *f << std::endl;
	delete f;
  } catch ( std::exception &e ) {
	std::cout << e.what() << std::endl;
  }
}

int main( void ) {
  Bureaucrat *arr[5] = {
      tryNewBureaucrat( "b1", 10 ), tryNewBureaucrat( "b2", 140 ),
      tryNewBureaucrat( "b3", 1 ), tryNewBureaucrat( "b4", 150 ),
      tryNewBureaucrat( "b5", 75 ) };

  Form *formArr[5] = {
	  tryNewForm( "f1", 0, 0 ), tryNewForm( "f2", 141, 141 ),
	  tryNewForm( "f3", 1, 1 ), tryNewForm( "f4", 2, 2 ),
	  tryNewForm( "f5", 75, 75 )
  };

  std::cout << std::endl;

  for ( size_t i = 0; i < 5; i++ ) {
    if ( arr[i] ) {
		for ( size_t j = 0; j < 5; j++ ) {
			if ( formArr[j] ) {
				arr[i]->signForm( *formArr[j] );
			}
		}
      tryDeleteBureaucrat( arr[i] );
      std::cout << std::endl;
    }
  }
  return 0;
}
