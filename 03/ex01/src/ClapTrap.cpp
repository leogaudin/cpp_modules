#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints,
		int attackDamage)
{
	std::cout << "ClapTrap: Custom constructor called" << std::endl;
	this->name = name;
	this->hitPoints = hitPoints;
	this->energyPoints = energyPoints;
	this->attackDamage = attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
	this->name = claptrap.name;
	this->hitPoints = claptrap.hitPoints;
	this->energyPoints = claptrap.energyPoints;
	this->attackDamage = claptrap.attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
		this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->hitPoints += amount;
		--this->energyPoints;
	}
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

std::string ClapTrap::getName() const
{
	return (this->name);
}

int ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

void ClapTrap::setHitPoints(int hitPoints)
{
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	this->attackDamage = attackDamage;
}
