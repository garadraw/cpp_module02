/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:36:32 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/08 15:57:42 by vsimeono         ###   ########.fr       */
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
	std::cout << " Copy Constructor Called" << std::endl;
	*this = src;
}

Fixed::Fixed(const float f)
{
	std::cout << " Float Constructor Called" << std::endl;
	this->_fixed_point = roundf(f * (1 << this->_static_int));
}

Fixed::Fixed(const int i)
{
	std::cout << "Integer Constructor Called" << std::endl;
	this->_fixed_point = i * (1 << this->_static_int);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &ref)
{
	return (stream << ref.toFloat());
}

Fixed &Fixed::operator=(Fixed const &src)
{
	if (this != &src)
	{
		this->_fixed_point = src.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits Function Called" << std::endl;
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

bool Fixed::operator>(Fixed const &ref) const
{
	return (this->getRawBits() > ref.getRawBits());
}

bool Fixed::operator>=(Fixed const &ref) const
{
	return (this->getRawBits() >= ref.getRawBits());
}

bool Fixed::operator<(Fixed const &ref) const
{
	return (this->getRawBits() < ref.getRawBits());
}

bool Fixed::operator<=(Fixed const &ref) const
{
	return (this->getRawBits() <= ref.getRawBits());
}

bool Fixed::operator==(Fixed const &ref) const
{
	return (this->getRawBits() == ref.getRawBits());
}
bool Fixed::operator!=(Fixed const &ref) const
{
	return (this->getRawBits() != ref.getRawBits());
}



Fixed Fixed::operator+(Fixed const &ref) const
{
	return (Fixed(this->toFloat() + ref.toFloat()));
}

Fixed Fixed::operator-(Fixed const &ref) const
{
	return (Fixed(this->toFloat() - ref.toFloat()));
}

Fixed Fixed::operator*(Fixed const &ref) const
{
	return (Fixed(this->toFloat() * ref.toFloat()));
}

Fixed Fixed::operator/(Fixed const &ref) const
{
	return (Fixed(this->toFloat() / ref.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->_fixed_point++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_fixed_point--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed &Fixed::min(Fixed &r1, Fixed &r2)
{
	return (r1 > r2 ? r2 : r1);
}

Fixed &Fixed::max(Fixed &r1, Fixed &r2)
{
	return (r1 > r2 ? r1 : r2);
}

const Fixed& Fixed::min(Fixed const &f1, Fixed const &f2){
	return (f1 > f2 ? f2 : f1);
}

const Fixed &Fixed::max(Fixed const &f1, Fixed const &f2)
{
	return (f1 > f2 ? f1 : f2);
}
