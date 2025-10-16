/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:54:02 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/16 10:05:04 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {
	Fixed a(42.42f);

	std::cout << a.getRawBits() << std::endl;
	std::cout << "float = " << a.toFloat() << std::endl;
	std::cout << "int = " << a.toInt() << std::endl;
	return 0;
}
