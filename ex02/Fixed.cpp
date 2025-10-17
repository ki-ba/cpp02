/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:28:43 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/16 09:58:09 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_nbFractionalBits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_value = (int)round(pow(2, this->_nbFractionalBits) * value);
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	// return ((float)this->_value / (1 << this->_nbFractionalBits)); // copilot
	return (((float)this->_value / pow(2, this->_nbFractionalBits)));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_nbFractionalBits);
}

int Fixed::getRawBits(void) const
{
	float returnValue;
	returnValue = 0;
	// std::cout << "getRawBits() member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(const int value)
{
	// std::cout << "setRawBits() member function called" << std::endl;
	this->_value = value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other._value;
	return (*this);
}


/* COMPARISON OPERATORS */

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}


/* ARITHMETIC OPERATORS */

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed sum ;
	sum._value = (this->_value + other._value);
	return (sum);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed sum ;
	sum._value = (this->_value - other._value);
	return (sum);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed sum ;
	sum._value = (this->_value * other._value) >> this->_nbFractionalBits;
	return (sum);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed sum ;
	sum._value = (this->_value / other._value) << this->_nbFractionalBits;
	return (sum);
}
	
/* INCREMENT & DECREMENT OPERATORS */

Fixed &Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed previous = *this;
	(this->_value)++;
	return (previous);
}

Fixed Fixed::operator--(int)
{
	Fixed previous = *this;
	(this->_value)--;
	return (previous);
}
/* MIN / MAX FUNCTIONS */

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream &stream, const Fixed &n)
{
	stream << n.toFloat();
	return (stream);
}

