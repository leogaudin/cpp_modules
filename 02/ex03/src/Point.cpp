/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:33:05 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/22 14:37:05 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0))
{
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y))
{
	std::cout << "Floating constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_x);
}

Point::Point(const Point &point): _x(point.getX()), _y(point.getY())
{
	std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &point)
{
	std::cout << "Copy assignment operator called" << std::endl;
	(void)point;
	return (*this);
}
