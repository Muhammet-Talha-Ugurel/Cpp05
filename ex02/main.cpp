#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

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

AForm *tryNewForm( std::string target ) {
  int r = rand() % 3;
  try {
    std::cout << "Creating new Form : " << target << std::endl;
    AForm *res;
    switch ( r ) {
      case 0:
        res = new RobotomyRequestForm( target );
        break;
      case 1:
        res = new RobotomyRequestForm( target );
        break;
      case 2:
        res = new RobotomyRequestForm( target );
        break;
      default:
        res = new RobotomyRequestForm( target );
        break;
    }
    std::cout << *res << std::endl;
    return res;
  } catch ( std::exception &e ) {
    std::cout << e.what() << std::endl;
  }
  return NULL;
}

void tryDeleteForm( AForm *f ) {
  try {
    std::cout << "Deleting " << *f << std::endl;
    delete f;
  } catch ( std::exception &e ) {
    std::cout << e.what() << std::endl;
  }
}

int main( void ) {
  Bureaucrat *arr[5] = { tryNewBureaucrat( "b1", 44 ), tryNewBureaucrat( "b2", 140 ),
                         tryNewBureaucrat( "b3", 1 ), tryNewBureaucrat( "b4", 150 ),
                         tryNewBureaucrat( "b5", 75 ) };

  AForm *formArr[5]  = { tryNewForm( "target1" ), tryNewForm( "target2" ), tryNewForm( "target3" ),
                         tryNewForm( "target4" ), tryNewForm( "target5" ) };

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
