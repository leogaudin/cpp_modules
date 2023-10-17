#include "../include/PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		std::cout << "Usage: ./PmergeMe [integers]" << std::endl;
		return 1;
	}
	PmergeMe(argc, const_cast<char **>(argv));
	return 0;
}

