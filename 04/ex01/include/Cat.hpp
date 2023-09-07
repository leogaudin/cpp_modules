#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
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
