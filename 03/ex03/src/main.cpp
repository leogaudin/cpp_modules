/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:53 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/06 15:38:19 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamondtrap("DiamondTrap");

	diamondtrap.takeDamage(1);
	diamondtrap.beRepaired(1);
	diamondtrap.highFivesGuys();
	diamondtrap.guardGate();
	diamondtrap.whoAmI();

	return (0);
}
