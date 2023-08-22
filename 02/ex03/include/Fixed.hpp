/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:26 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/21 18:16:22 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# define SHIFT_AMOUNT 8
# define SHIFT_MASK ((1 << SHIFT_AMOUNT) - 1)

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int value;
	static const int fractional_bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	Fixed(const int integer);
	Fixed(const float floating);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(Fixed const &next);
	bool operator<(Fixed const &next);
	bool operator<=(Fixed const &next);
	bool operator>=(Fixed const &next);
	bool operator==(Fixed const &next);
	bool operator!=(Fixed const &next);

	Fixed operator+(Fixed const &next);
	Fixed operator-(Fixed const &next);
	Fixed operator*(Fixed const &next);
	Fixed operator/(Fixed const &next);

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(const Fixed &first, const Fixed &second);
	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream &operator<<(std::ostream &output, Fixed const &input);

#endif
