/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:53 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/22 15:07:00 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include <iomanip>

# define BLACK "\033[0;30m"
# define DARK_GRAY "\033[1;30m"
# define RED "\033[0;31m"
# define BOLD_RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define BOLD_GREEN "\033[1;32m"
# define BROWN_ORANGE "\033[0;33m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define BOLD_BLUE "\033[1;34m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define CYAN "\033[0;36m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[0;37m"
# define RESET "\033[0;37m"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed denominator = ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
    Fixed alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
    Fixed beta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
    Fixed gamma = Fixed(1.0f) - alpha - beta;

	std::cout << YELLOW "Alpha: " << alpha.toFloat() << std::endl;
	std::cout << YELLOW "Beta: " << beta.toFloat() << std::endl;
	std::cout << YELLOW "Gamma: " << gamma.toFloat() << std::endl;
	std::cout << RESET;

    return alpha >= 0 && beta >= 0 && gamma >= 0;
}

int	main(void)
{
	float x_test = 500;
	float y_test = 100;

	bool result = bsp(
			Point(-5, 1),
			Point(3, 5),
			Point(5, 2),
			Point(x_test, y_test)
		);

	std::cout << BOLD_PURPLE "Is (" << x_test << ", "<< y_test << ") in the triangle ? ";
	if (result == true)
		std::cout << BOLD_GREEN " Yes !";
	else if (result == false)
		std::cout << BOLD_RED " No !";
	std::cout << RESET << std::endl;
	return (0);
}
