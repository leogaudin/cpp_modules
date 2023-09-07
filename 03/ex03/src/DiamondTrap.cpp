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

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
	: ClapTrap("default_clap_name"), FragTrap("default_frag_name"), ScavTrap("default_scav_name")
{
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
	*this = diamondtrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	this->name = diamondtrap.name;
	return (*this);
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
