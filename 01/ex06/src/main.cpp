/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:53 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/17 14:50:29 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl harl;
	if (argc == 2)
	{
		harl.complain(argv[1]);
		return (EXIT_SUCCESS);
	}
	else
	{
		std::cout
			<< BOLD_RED "Usage: ./harlFilter <level>" RESET
			<< std::endl;
		return (EXIT_FAILURE);
	}
}
