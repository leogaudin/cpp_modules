#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
	this->name = name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = claptrap.name;
	this->hitPoints = claptrap.hitPoints;
	this->energyPoints = claptrap.energyPoints;
	this->attackDamage = claptrap.attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		--this->energyPoints;
		std::cout
			<< "ClapTrap "
			<< this->name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->attackDamage
			<< " points of damage!"
			<< std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
		this->hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->hitPoints += amount;
		--this->energyPoints;
	}
}

