#include "../include/Intern.hpp"

int	main(void)
{
	Intern	someRandomIntern;
	Form	*rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	return (0);
}
