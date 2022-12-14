/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:33:05 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/08 15:25:32 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

const int	Fixed::_static_int = 8;

Fixed::Fixed(void): _fixed_point(0)
{
	std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(Fixed const &src)
{
	if (this != &src)
	{
		std::cout << "Copy Assignment Operator Called" << std::endl;
		this->_fixed_point = src.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits Member function Called" << std::endl;
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

