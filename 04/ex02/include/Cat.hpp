#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
  public:
	Cat();
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);
	~Cat();
	void makeSound() const;

  private:
	Brain *brain;

};

#endif
