#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), target(target)
{
	// std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf): Form(rrf.getName(), rrf.getGradeToSign(), rrf.getGradeToExecute()), target(rrf.target)
{
	// std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
	*this = rrf;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
	// std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
	(void)rrf;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();
	else if (!getIsSigned())
		throw Form::FormNotSignedException();
	else
	{
		std::cout << "* drilling noises *" << std::endl;
		if (std::rand() % 2)
			std::cout << target << " has been robotomized successfully" << std::endl;
		else
			std::cout << target << " robotomization failed" << std::endl;
	}
}
