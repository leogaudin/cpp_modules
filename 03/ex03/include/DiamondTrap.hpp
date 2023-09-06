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
	~DiamondTrap();
	void whoAmI();

  private:
	std::string name;
};

#endif
