#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->ClapTrap::setName(name + "_clap_name");
	std::cout << "DiamondTrap: Default constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout
		<< "DiamondTrap: My name is "
		<< this->name
		<< " and my ClapTrap name is "
		<< this->ClapTrap::getName()
		<< std::endl;
}
