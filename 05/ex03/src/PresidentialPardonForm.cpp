#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", 25, 5), target(target)
{
	// std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf)
	: Form(ppf.getName(), ppf.getGradeToSign(), ppf.getGradeToExecute()),
		target(ppf.target)
{
	// std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
	*this = ppf;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
	// std::cout << "PresidentialPardonForm: Copy assignment operator called" << std::endl;
	(void)ppf;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();
	else if (!getIsSigned())
		throw Form::FormNotSignedException();
	else
		std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
