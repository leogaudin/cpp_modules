/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:53:47 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/17 11:18:21 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
	Zombie *zombie_horde = zombieHorde(7, "Bruno");
	for (int i = 0; i < 7; i++)
		zombie_horde[i].announce();
	delete[] zombie_horde;
	return (0);
}
