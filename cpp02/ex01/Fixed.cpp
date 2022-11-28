/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:45:54 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/21 18:42:15 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Fixed.hpp"
#include	<iostream>

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	// *this = fixed;
	// 같은 주소를 갖게되나 ? 아님 내용을 복사만 하나? 아직 이해가 부족한 것 같다. 
	// const 니까 괜찮지 않나
}

Fixed::Fixed(const int num)
{
	this->fixed_point = num << fraction;
}

Fixed::Fixed(const float num)
{
	this->fixed_point = roundf(num * (1 << 8)); // ??????????????
	// It converts it to the corresponding fixed-point value.
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assaignment operator called" << std::endl;
	this->fixed_point = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
//	std::cout << "getRawBits memeber function called" << std::endl;
	return this->fixed_point;
}

void	Fixed::setRawBits( int const raw )
{
//	std::cout << "setRawBits memeber function called" << std::endl;
	this->fixed_point = raw;
}

float	Fixed::toFloat( void ) const
{
	///
	
	return (float)this->getRawBits() / (1 << fraction);
}

int	Fixed::toInt( void ) const
{
	///

	return this->getRawBits() >> fraction;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	// .
	// 
	return os;
}
