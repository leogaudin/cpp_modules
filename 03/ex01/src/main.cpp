/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:53 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/06 13:10:03 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int	main(void)
{
	ScavTrap scavtrap("Scavtrap");

	scavtrap.attack("Handsome Jack");
	scavtrap.takeDamage(1);
	scavtrap.beRepaired(1);
	scavtrap.guardGate();

	return (0);
}
