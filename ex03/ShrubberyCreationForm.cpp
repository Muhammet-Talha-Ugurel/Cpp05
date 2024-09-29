#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() {
  throw std::invalid_argument( "ShrubberyCreationForm: default constructor is not allowed" );
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) :
    AForm( "Shrubbery Creation Form", 145, 137 ), _target( target ) {
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &copy ) :
    AForm( copy ), _target( copy._target ) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &assign ) {
  if ( this != &assign ) {
    AForm::operator=( assign );
  }
  return *this;
}

void ShrubberyCreationForm::execute( const Bureaucrat &executor ) const {
  if ( getGradeToExecute() < executor.getGrade() )
    throw GradeTooLowException();
  std::string filename = _target + "_shrubbery";
  std::ofstream file( filename.c_str() );
  if ( !file.is_open() )
    throw std::runtime_error( "ShrubberyCreationForm: cannot open file" );
  file << "      /\\      " << std::endl;
  file << "     /\\*\\     " << std::endl;
  file << "    /\\O\\*\\    " << std::endl;
  file << "   /*/\\/\\/\\   " << std::endl;
  file << "  /\\O\\/\\*\\/\\  " << std::endl;
  file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
  file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << "      ||      " << std::endl;
  file << std::endl;
  file.close();
}
