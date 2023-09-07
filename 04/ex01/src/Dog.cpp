#include "../include/Dog.hpp"

Dog::Dog(): Animal("dog")
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
	delete this->brain;
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
	this->brain = new Brain(*dog.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
}
