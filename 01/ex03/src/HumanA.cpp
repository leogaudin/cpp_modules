/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:42:00 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/17 13:04:13 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
	std::cout
		<< this->name << " attacks with their " << this->weapon.getType()
		<< std::endl;
}
