#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap("", 100, 50, 20)
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	this->setName(name);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap): ClapTrap("")
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	this->setName(scavtrap.getName());
	this->setHitPoints(scavtrap.getHitPoints());
	this->setEnergyPoints(scavtrap.getEnergyPoints());
	this->setAttackDamage(scavtrap.getAttackDamage());
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	this->setName(scavtrap.getName());
	this->setHitPoints(scavtrap.getHitPoints());
	this->setEnergyPoints(scavtrap.getEnergyPoints());
	this->setAttackDamage(scavtrap.getAttackDamage());
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout
			<< "ScavTrap "
			<< this->getName()
			<< " attacks "
			<< target
			<< ", causing "
			<< this->getAttackDamage()
			<< " points of damage!"
			<< std::endl;
	}
}
