/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:21:42 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/08 11:53:23 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/colors.h"
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
	startup();
}

void PhoneBook::startup(void)
{
	std::cout << std::endl
				<< BOLD_PURPLE "~ TUDUDUTU TUDUDUTU TUDUDUTUTUUU ~" RESET << std::endl
				<< std::endl;
	std::cout << std::endl
				<< BOLD_PURPLE "Welcome to your brand new Nokia 3310!" BLACK " (Snake is not installed sorry)" RESET << std::endl
				<< std::endl;
	std::cout << YELLOW "You can enter one of the 3 following commands:" RESET << std::endl
				<< std::endl;
	std::cout << BOLD_GREEN "ADD:\t" RESET " save a new contact" << std::endl;
	std::cout << BOLD_GREEN "SEARCH:\t" RESET " display a specific contact" << std::endl;
	std::cout << BOLD_RED "EXIT:\t" RESET " quit and lose all your saved friends" << std::endl;
}

void PhoneBook::shift_contacts(void)
{
	for (int i = 0; i < 7; i++)
		this->contacts[i] = this->contacts[i + 1];
}

void PhoneBook::add(void)
{
	int	i;

	i = 0;
	while (!this->contacts[i].empty() && i <= 7)
		i++;
	if (i >= 7)
		this->shift_contacts();
	this->contacts[i].create();
	std::cout << BOLD_GREEN << this->contacts[i].get_first_name() << " was successfully added!" RESET << std::endl;
}

void PhoneBook::get_contact_prompt(void)
{
	std::string buffer;

	while (1)
	{
		std::cout << YELLOW "Enter the index of the contact you want to display: " RESET;
		std::flush(std::cout);
		std::getline(std::cin, buffer);
		if (buffer.find_first_not_of("01234567") != std::string::npos
			|| buffer.empty() || buffer.length() > 1)
		{
			std::cout << BOLD_RED "Invalid index, please choose one in the above list" RESET << std::endl;
			continue ;
		}
		else
		{
			if (this->contacts[stoi(buffer)].empty())
			{
				std::cout << BOLD_RED "This contact doesn't exist, please choose one in the above list" RESET << std::endl;
				continue ;
			}
			this->contacts[stoi(buffer)].print();
			break;
		}
	}
}

void PhoneBook::search(void)
{
	std::cout << " -----------------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!this->contacts[i].empty())
		{
			std::cout << " | ";
			std::cout << std::setw(16);
			std::cout << BOLD_CYAN << i << RESET;
			std::cout << " | ";
			std::cout << std::setw(10);
			std::cout << this->contacts[i].get_first_name();
			std::cout << " | ";
			std::cout << std::setw(10);
			std::cout << this->contacts[i].get_last_name();
			std::cout << " | ";
			std::cout << std::setw(10);
			std::cout << this->contacts[i].get_nickname();
			std::cout << " | ";
			std::cout << std::endl;
			std::cout << " -----------------------------------------------------" << std::endl;
		}
	}
	get_contact_prompt();
}
