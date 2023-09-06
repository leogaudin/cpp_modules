#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap: public ClapTrap
{
  public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &scavtrap);
	FragTrap &operator=(const FragTrap &scavtrap);
	~FragTrap();
	void attack(const std::string &target);
	void highFivesGuys(void);

  private:

};

#endif
