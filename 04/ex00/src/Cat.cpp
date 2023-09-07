#include "../include/Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	this->type = "cat";
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	this->type = cat.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}
