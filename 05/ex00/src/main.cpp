#include "../include/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat bureaucrat("Bureaucrat", 1);
		std::cout << bureaucrat << std::endl;
		// Should be 2
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		// Should be 1
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		// Should be 0 and throw exception
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------" << std::endl;
	try
	{
		// Should throw exception
		Bureaucrat bureaucrat("Bureaucrat", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
