#include "../include/FragTrap.hpp"

FragTrap::FragTrap(std::string name)
	: ClapTrap("", 100, 100, 30)
{
	std::cout << "FragTrap: Default constructor called" << std::endl;
	this->setName(name);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap)
	: ClapTrap("")
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	this->setName(fragtrap.getName());
	this->setHitPoints(fragtrap.getHitPoints());
	this->setEnergyPoints(fragtrap.getEnergyPoints());
	this->setAttackDamage(fragtrap.getAttackDamage());
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	this->setName(fragtrap.getName());
	this->setHitPoints(fragtrap.getHitPoints());
	this->setEnergyPoints(fragtrap.getEnergyPoints());
	this->setAttackDamage(fragtrap.getAttackDamage());
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout
			<< "FragTrap "
			<< this->getName()
			<< " attacks "
			<< target
			<< ", causing "
			<< this->getAttackDamage()
			<< " points of damage!"
			<< std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: High fives guys!" << std::endl;
}
