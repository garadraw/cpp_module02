/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:33:14 by vsimeono          #+#    #+#             */
/*   Updated: 2022/11/08 15:57:03 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int					_fixed_point;
		int static const	_static_int;

	public:
		Fixed(void);
		Fixed &operator=(Fixed const &src);
		Fixed (Fixed const &src);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif