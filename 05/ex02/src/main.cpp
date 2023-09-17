#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat bureaucrat("Jacquouille", 11);
		ShrubberyCreationForm form("Home");
		RobotomyRequestForm robot("Robot");
		PresidentialPardonForm president("President");
		bureaucrat.signForm(form);
		bureaucrat.signForm(robot);
		bureaucrat.signForm(president);
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(robot);
		bureaucrat.executeForm(president);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
