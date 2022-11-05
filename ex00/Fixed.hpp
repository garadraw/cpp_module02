/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nartex <nartex@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:21:00 by nartex            #+#    #+#             */
/*   Updated: 2022/11/05 18:21:01 by nartex           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
// #include <string>

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