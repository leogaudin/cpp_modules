#include "../include/Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->type = "dog";
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	this->type = dog.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
}
