/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:33:07 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/21 18:52:41 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
  public:
	Point();
	Point(const float x, const float y);
	Point(const Point &point);
	Point &operator=(const Point &point);
	~Point();
	Fixed getX(void) const;
	Fixed getY(void) const;

  private:
	const Fixed _x;
	const Fixed _y;
};

#endif
