/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:53:47 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/17 10:50:08 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

/**
 * The output of this main is the following:
 *
 * Romuald: BraiiiiiiinnnzzzZ...
 * Bernard: BraiiiiiiinnnzzzZ...
 * Bernardeau: BraiiiiiiinnnzzzZ...
 * Bernardeau is now really dead.
 * Bernard is now really dead.
 *
 * We can see that creating a zombie on the heap will make it persistent
 * unless it's deleted.
 * On the stack however, it is destroyed at the end of the execution of the
 * function.
 * The randomChump() function shows about the same behaviour, but inside its
 * own function, therefore before the main() has even finished executing.
 */
int main(void)
{
	Zombie *zombie_heap = newZombie("Romuald");
	zombie_heap->announce();

	Zombie zombie_stack("Bernard");
	zombie_stack.announce();

	randomChump("Bernardeau");
	return (0);
}
