#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(const WrongCat &cat);
	WrongCat &operator=(const WrongCat &cat);
	~WrongCat();
	void makeSound() const;

  private:

};

#endif
