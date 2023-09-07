#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
  public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamondtrap);
	DiamondTrap &operator=(const DiamondTrap &diamondtrap);
	~DiamondTrap();
	using FragTrap::attack;
	void whoAmI();

  private:
	std::string name;
};

#endif
