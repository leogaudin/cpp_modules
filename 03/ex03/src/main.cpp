/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:53 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/07 11:29:30 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamondtrap("DiamondTrap");

	diamondtrap.takeDamage(1);
	diamondtrap.beRepaired(1);
	diamondtrap.attack("target");
	diamondtrap.highFivesGuys();
	diamondtrap.guardGate();
	diamondtrap.whoAmI();

	return (0);
}
