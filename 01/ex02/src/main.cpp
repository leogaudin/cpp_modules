/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:53:47 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/17 12:07:30 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	std::cout
		<< "Memory address of the string variable: " << &str << std::endl
		<< "Memory address held by stringPTR: " << &stringPTR << std::endl
		<< "Memory address held by stringREF: " << &stringREF << std::endl
		<< std::endl
		<< "Value of the string variable: " << str << std::endl
		<< "Value pointed to by stringPTR: " << stringPTR << std::endl
		<< "Value pointed to by stringREF: " << stringREF << std::endl;
}
