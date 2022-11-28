/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:19 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/24 16:34:40 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Fixed.hpp"
#include	<iostream>
#include	<cmath> // roundf
#include	<bitset>

int main( void ) {
	Fixed		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl << "test" << (float)roundf(42.42f * (1 << 8)) /256 << std::endl;
	
	std::cout << std::endl << "test" << (int)roundf(42.42f * (1 << 8))  << std::endl;

	std::cout << std::endl << "test" << 1.0f * (1 << 8) << std::endl;

	float	f = 42.42;
	std::cout << std::bitset<32>(f) << std::endl;

	return 0; 
}
