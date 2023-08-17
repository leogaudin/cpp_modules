/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:53:47 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/17 13:47:05 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void	ft_replace(std::string filename, std::string s1, std::string s2)
{
	size_t	index;

	std::string buffer;
	std::ifstream ifs(filename);
	if (ifs.is_open())
	{
		std::ofstream ofs(filename + ".replace");
		std::getline(ifs, buffer, '\0');
		index = buffer.find(s1);
		while (index != std::string::npos)
		{
			buffer.erase(index, s1.length());
			buffer.insert(index, s2);
			index = buffer.find(s1);
		}
		ifs.close();
		ofs << buffer;
		ofs.close();
	}
	else
		std::cout << "Error opening file " << filename << std::endl;
}

int	main(void)
{
	{
		// Inexistent file: should throw error
		ft_replace("tester", "Claude", "Jean-Jacques");
	}

	{
		// Existent file but test.replace should be the same as test
		ft_replace("test", "Mélodie", "Claude");
	}

	{
		// Existent file and test.replace should have "Jean-Jacques" everywhere
		ft_replace("test", "Claude", "Jean-Jacques");
		// Existent file and test.replace.replace should be back to initial
		ft_replace("test.replace", "Jean-Jacques", "Claude");
	}
	return (0);
}
