/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:33:00 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/22 14:35:14 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

// bool	bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed	s;
// 	Fixed	t;
// 	Fixed	d;

// 	s = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY()
// 			- c.getY()) * (point.getX() - c.getX());
// 	t = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY()
// 			- a.getY()) * (point.getX() - a.getX());
// 	if ((s < 0) != (t < 0) && s != 0 && t != 0)
// 		return (false);
// 	d = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY()
// 			- b.getY()) * (point.getX() - b.getX());
// 	return (d == 0 || (d < 0) == (s + t <= 0));
// }
