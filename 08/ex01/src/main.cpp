#include "../include/Span.hpp"

int	main(void)
{
	std::vector<int> array(10000);
	std::srand(time(NULL));
	std::generate(array.begin(), array.end(), std::rand);

	Span span(array.size());
	span.addNumber(array.begin(), array.end());
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
}
