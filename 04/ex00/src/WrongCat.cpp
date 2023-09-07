#include "../include/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
	this->type = "cat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	*this = cat;
}

WrongCat &WrongCat::operator=(const WrongCat &cat)
{
	std::cout << "WrongCat: Copy assignment operator called" << std::endl;
	this->type = cat.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}
