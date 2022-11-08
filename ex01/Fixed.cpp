/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:31:38 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/08 15:25:13 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_static_int = 8;

Fixed::Fixed(void): _fixed_point(0)
{
	std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor Called" << std::endl;
	*this = src;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float Constructor Called" << std::endl;
	this->_fixed_point = roundf(f * (1 << this->_static_int));
}

Fixed::Fixed(const int i)
{
	std::cout << "Integer Constructor Called" << std::endl;
	this->_fixed_point = i * (1 << this->_static_int);
}

Fixed &Fixed::operator=(Fixed const &src)
{
	if (this != &src)
	{
		std::cout << "Copy Assignment Operator Called" << std::endl;
		this->_fixed_point = src.getRawBits();
	}
	return(*this);
}

int Fixed::getRawBits(void) const 
{
	return this->_fixed_point;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor Called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}

float	Fixed::toFloat(void) const 
{
	return ((double)this->getRawBits() / (float)(1 << this->_static_int));
	
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() / (1 << this->_static_int));
}

std::ostream &operator<<(std::ostream &stream, Fixed const &ref)
{
	return (stream << ref.toFloat());
}

