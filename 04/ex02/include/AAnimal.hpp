#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
  public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &animal);
	AAnimal &operator=(const AAnimal &animal);
	virtual ~AAnimal();
	virtual void makeSound() const = 0;
	std::string getType() const;

  protected:
	std::string type;

};

#endif
