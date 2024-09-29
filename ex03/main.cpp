#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

Bureaucrat *tryNewBureaucrat( std::string name, int grade ) {
  try {
    std::cout << "Creating new Bureaucrat : " << name << " | grade : " << grade << std::endl;
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

const std::string formNamesToTest[] = { "robotomy", "presidential", "unknown", "shrubbery",
                                         "presidential pardon" };

AForm *tryNewForm( std::string target ) {
  try {
    std::cout << "Creating new Form : " << target << std::endl;
    Intern i;
    AForm *res = i.makeForm( formNamesToTest[rand() % 4], target );
    std::cout << *res << std::endl;
    return res;
  } catch ( std::exception &e ) {
    std::cout << e.what() << std::endl;
  	return NULL;
  }
}

void tryDeleteForm( AForm *f ) {
  try {
    std::cout << "Deleting " << *f << std::endl;
  } catch ( std::exception &e ) {
    std::cout << e.what() << std::endl;
  }
}

int main( void ) {
  Bureaucrat *arr[5] = { tryNewBureaucrat( "b1", 44 ), tryNewBureaucrat( "b2", 140 ),
                         tryNewBureaucrat( "b3", 1 ), tryNewBureaucrat( "b4", 150 ),
                         tryNewBureaucrat( "b5", 75 ) };

  std::cout << std::endl;

  AForm *formArr[5]  = { tryNewForm( "target1" ), tryNewForm( "target2" ), tryNewForm( "target3" ),
                         tryNewForm( "target4" ), tryNewForm( "target5" ) };

  std::cout << std::endl;

  for ( size_t i = 0; i < 5; i++ ) {
    if ( arr[i] ) {
      for ( size_t j = 0; j < 5; j++ ) {
		std::cout << i << " " << j << std::endl;
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
