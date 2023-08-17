/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:21:36 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/16 17:05:19 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/colors.h"

Contact::Contact(void)
{
	// create();
	// print();
}

std::string Contact::prompt(std::string prompt)
{
	std::string buffer = "";
	std::cout << prompt;
	std::flush(std::cout);
	std::getline(std::cin, buffer);
	if (buffer.empty())
		return (this->prompt(prompt));
	return (buffer);
}

void Contact::create(void)
{
	std::cout << GREEN "Enter the contact information:" RESET << std::endl;
	this->first_name = this->prompt("First name: ");
	this->last_name = this->prompt("Last name: ");
	this->nickname = this->prompt("Nickname: ");
	this->phone_number = this->prompt("Phone number: ");
	this->secret = this->prompt("Darkest secret: ");
}

void Contact::print(void)
{
	std::cout << PURPLE "First name: " RESET << this->first_name << std::endl;
	std::cout << PURPLE "Last name: " RESET << this->last_name << std::endl;
	std::cout << PURPLE "Nickname: " RESET << this->nickname << std::endl;
	std::cout << PURPLE "Phone number: " RESET << this->phone_number << std::endl;
	std::cout << PURPLE "Darkest secret: " RESET << this->secret << std::endl;
}

bool Contact::empty(void)
{
	return (first_name.empty() || last_name.empty() || nickname.empty()
		|| phone_number.empty() || secret.empty());
}

std::string Contact::get_first_name(void)
{
	std::string ret = this->first_name;
	if (ret.length() > 10)
		return (ret.substr(0, 9) + ".");
	return (ret);
}

std::string Contact::get_last_name(void)
{
	std::string ret = this->last_name;
	if (ret.length() > 10)
		return (ret.substr(0, 9) + ".");
	return (ret);
}

std::string Contact::get_nickname(void)
{
	std::string ret = this->nickname;
	if (ret.length() > 10)
		return (ret.substr(0, 9) + ".");
	return (ret);
}
