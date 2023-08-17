/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:40 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/17 14:09:17 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

void Harl::debug(void)
{
	std::cout
		<< BOLD_WHITE
		<< "I love having extra gruyère for my 7XL-double-cheese-triple-pickle-special- ketchup ravioli. I really do!"
		<< RESET
		<< std::endl;
}

void Harl::info(void)
{
	std::cout
		<< BOLD_BLUE
		<< "I cannot believe adding extra gruyère costs more money. You didn't put enough gruyère in my ravioli! If you did, I wouldn't be asking for more!"
		<< RESET
		<< std::endl;
}

void Harl::warning(void)
{
	std::cout
		<< BOLD_YELLOW
		<< "I think I deserve to have some extra gruyère for free. I've been coming for years whereas you started working here since last month."
		<< RESET
		<< std::endl;
}

void Harl::error(void)
{
	std::cout
		<< BOLD_RED
		<< "This is unacceptable! I want to speak to Ratatouille now."
		<< RESET
		<< std::endl;
}

void Harl::complain(std::string level)
{
	t_function	functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (level.compare(levels[i]) && i <= 4)
		i++;
	if (i >= 4)
		std::cout
			<< BOLD_RED
			<< "YOU HAVE TO CHOOSE AN EXISTING LEVEL IT'S NOT THAT COMPLICATED"
			<< RESET
			<< std::endl;
	else
		(this->*functions[i])();
}
