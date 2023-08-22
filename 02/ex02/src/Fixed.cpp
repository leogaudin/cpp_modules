/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:40 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/21 18:27:17 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(fixed.getRawBits());
}

// https://stackoverflow.com/questions/10067510/fixed-point-arithmetic-in-c-programming

/**
 * @brief
 * The calculation "value = floating * (1 << this->fractional_bits)" can be
 * explained as follows, with the example of:
 *
 * floating = 0.75
 * fractional_bits = 16
 *
 * In binary, 1 is 0000000000000001.
 * When we shift it by 16, it becomes 00000000000000010000000000000000, which
 * is 65536.
 *
 * We then multiply 0.75 by 65536 (= 49152) and store it.
 *
 * Given that we know we are going to keep the same fractional_bits value, we
 * know that 49152 is the equivalent of 0.75.
 *
 * @param    floating
 */
Fixed::Fixed(const float floating)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = floating * (1 << this->fractional_bits);
}
/**
 * @brief
 * Representing an integer in fixed point is pretty straightforward.
 *
 * Given that it has no fractional part, we can simply left-shift it
 * fractional_bits times, given that everything at the right of the binary
 * is and needs to be 0.
 *
 * @param    integer
 */
Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = integer << this->fractional_bits;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->value) / (1 << this->fractional_bits);
}

int Fixed::toInt(void) const
{
	return (this->value >> this->fractional_bits);
}

std::ostream &operator<<(std::ostream &output, Fixed const &input)
{
	output << input.toFloat();
	return (output);
}

bool Fixed::operator>(Fixed const &next)
{
	return (this->getRawBits() > next.getRawBits());
}

bool Fixed::operator<(Fixed const &next)
{
	return (this->getRawBits() < next.getRawBits());
}

bool Fixed::operator<=(Fixed const &next)
{
	return (this->getRawBits() <= next.getRawBits());
}

bool Fixed::operator>=(Fixed const &next)
{
	return (this->getRawBits() >= next.getRawBits());
}

bool Fixed::operator==(Fixed const &next)
{
	return (this->getRawBits() == next.getRawBits());
}

bool Fixed::operator!=(Fixed const &next)
{
	return (this->getRawBits() != next.getRawBits());
}

Fixed Fixed::operator+(Fixed const &next)
{
	return (Fixed(this->toFloat() + next.toFloat()));
}

Fixed Fixed::operator-(Fixed const &next)
{
	return (Fixed(this->toFloat() - next.toFloat()));
}

Fixed Fixed::operator*(Fixed const &next)
{
	return (Fixed(this->toFloat() * next.toFloat()));
}

Fixed Fixed::operator/(Fixed const &next)
{
	return (Fixed(this->toFloat() / next.toFloat()));
}

// Pre-increment
Fixed &Fixed::operator++()
{
	this->value++;
	return (*this);
}

// Post-increment
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	tmp.value = this->value;
	this->value++;
	return (tmp);
}

// Pre-decrement
Fixed &Fixed::operator--()
{
	this->value--;
	return (*this);
}

// Post-decrement
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	tmp.value = this->value;
	this->value--;
	return (tmp);
}

Fixed& Fixed::min(Fixed &first, Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}
