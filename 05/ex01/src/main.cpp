#include "../include/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat bureaucrat("Jacquouille", 11);
		Form form("Budget", 10, 25);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
