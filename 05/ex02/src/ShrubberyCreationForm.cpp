#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 145, 137), target(target)
{
	// std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
	: Form(scf.getName(), scf.getGradeToSign(), scf.getGradeToExecute()),
		target(scf.target)
{
	// std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
	*this = scf;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
	// std::cout << "ShrubberyCreationForm: Copy assignment operator called" << std::endl;
	(void)scf;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();
	else if (!getIsSigned())
		throw Form::FormNotSignedException();
	else
	{
		std::ofstream file;
		file.open((target + "_shrubbery"));
		file << "      /\\\n";
		file << "     /\\*\\\n";
		file << "    /\\O\\*\\\n";
		file << "   /*/\\/\\/\\\n";
		file << "  /\\O\\/\\*\\/\\\n";
		file << " /\\*\\/\\*\\/\\/\\\n";
		file << "/\\O\\/\\/*/\\/O/\\\n";
		file << "      ||\n";
		file << "      ||\n";
		file << "      ||\n";
		file << std::endl;
		file.close();
	}
}
