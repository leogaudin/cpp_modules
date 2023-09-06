/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:53 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/06 15:18:31 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

int	main(void)
{
	FragTrap fragtrap("Jean la Couille");

	fragtrap.attack("Handsome Jack");
	fragtrap.takeDamage(1);
	fragtrap.beRepaired(1);
	fragtrap.highFivesGuys();

	return (0);
}
