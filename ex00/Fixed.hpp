/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:18:14 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/16 09:47:36 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
	int                 _value;
	static const int	_nbFractionalBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(Fixed &other);
	Fixed& operator=(const Fixed &other);

	int					getRawBits(void);
	void				setRawBits(int const raw); // same as const int raw
	
};

#endif
