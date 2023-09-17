#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern()
{
	// std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::~Intern()
{
	// std::cout << "Intern: Destructor called" << std::endl;
}

Intern::Intern(const Intern &intern)
{
	// std::cout << "Intern: Copy constructor called" << std::endl;
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	// std::cout << "Intern: Copy assignment operator called" << std::endl;
	(void)intern;
	return (*this);
}

Form *Intern::makeForm(std::string name, std::string target)
{
	Form *forms[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (forms[i]);
		}
	}
	return (NULL);
}
