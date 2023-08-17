/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:21:40 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/16 16:40:39 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string buffer;
	while (buffer.compare("EXIT"))
	{
		std::cout << BOLD_CYAN "~ " RESET;
		std::flush(std::cout);
		std::getline(std::cin, buffer);
		if (!buffer.compare("ADD"))
			book.add();
		else if (!buffer.compare("SEARCH"))
			book.search();
	}
	return (0);
}
