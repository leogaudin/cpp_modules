#include "../include/Cat.hpp"

Cat::Cat(): AAnimal("cat")
{
	std::cout << "Cat: Default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
	delete this->brain;
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
	this->brain = new Brain(*cat.brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}
