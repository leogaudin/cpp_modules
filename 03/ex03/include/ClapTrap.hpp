#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
  public:
	ClapTrap(std::string name);
	ClapTrap(std::string name, int hitPoints, int energyPoints,
			int attackDamage);
	ClapTrap(const ClapTrap &claptrap);
	ClapTrap &operator=(const ClapTrap &claptrap);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void setName(std::string name);
	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
	void setHitPoints(int hitPoints);
	void setEnergyPoints(int energyPoints);
	void setAttackDamage(int attackDamage);

  private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
};

#endif
