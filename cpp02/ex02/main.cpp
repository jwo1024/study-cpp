/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:19 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/02 23:57:29 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Fixed.hpp"
#include	<iostream>

int main( void ) {
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// Fixed 		a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << "a: " << a << std::endl;
	// std::cout << "++a: "<< ++a << std::endl;
	// std::cout << "a: " << a << std::endl;
	// std::cout << "a++: " << a++ << std::endl;
	// std::cout << "a: " << a << std::endl;

	// std::cout << "b: " << b << std::endl;

	// std::cout << "max(a,b): "<< Fixed::max( a, b ) << std::endl;
	// std::cout << "min(a,b): "<< Fixed::min( a, b ) << std::endl;


	// Fixed const c( 42.25f);
	// Fixed		d( 42.25f);

	// std::cout << "max(a,d): "<< Fixed::max( a, d ) << std::endl;
	
	// a > d ? std::cout << "a > d true" << std::endl :std::cout << "a > d false" << std::endl;
	// a < d ? std::cout << "a < d true" << std::endl :std::cout << "a < d false" << std::endl;
	// a >= b ? std::cout << "a >= b true" << std::endl :std::cout << "a >= b false" << std::endl;
	// c <= d ? std::cout << "c <= d true" << std::endl :std::cout << "c <= d false" << std::endl;
	// c == d ? std::cout << "c == d true" << std::endl :std::cout << "c == d false" << std::endl;
	// c != d ? std::cout << "c != d true" << std::endl :std::cout << "c != d false" << std::endl;

	// Fixed	e = c + d;
	// std::cout << c << "(c) + "  << d << "(d) = " << e << std::endl;
	// e = c * 2;
	// std::cout << c << "(c) * "  << 2 << " = " << e << std::endl;
	// std::cout << e << "(e) / "  << 2 << " = " << e / 2 << std::endl;
	// std::cout << "e = " << e << ", e - 0.25f = " << e - 0.25f << std::endl;
	// std::cout << "e = " << e << ", e + 0.125f = " << e + 0.125f << std::endl;

	return 0; 
}
