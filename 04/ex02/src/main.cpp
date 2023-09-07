#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int	main(void)
{
	const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    const AAnimal* animals[4] = {
		new Dog(), new Cat(), new Dog(), new Cat()
	};
    for (int i = 0; i < 4; i++)
        delete animals[i];

	return (0);
}
