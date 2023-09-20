#include "../include/iter.hpp"

void	print(int &i)
{
	std::cout << i << " ";
}

void	add(int &i)
{
	i += 1;
}

void	sub(int &i)
{
	i -= 1;
}

void	mul(int &i)
{
	i *= 2;
}

void	div(int &i)
{
	i /= 2;
}

// int	main(void)
// {
// 	int	a[5] = {1, 2, 3, 4, 5};
// 	std::cout << "Initially:\t";
// 	iter(a, 5, print);
// 	std::cout << std::endl;
// 	iter(a, 5, add);
// 	std::cout << "After add():\t";
// 	iter(a, 5, print);
// 	std::cout << std::endl;
// 	std::cout << "After sub():\t";
// 	iter(a, 5, sub);
// 	iter(a, 5, print);
// 	std::cout << std::endl;
// 	iter(a, 5, mul);
// 	std::cout << "After mul():\t";
// 	iter(a, 5, print);
// 	std::cout << std::endl;
// 	iter(a, 5, div);
// 	std::cout << "After div():\t";
// 	iter(a, 5, print);
// 	std::cout << std::endl;
// 	return (0);
// }
