/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:45:54 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/02 23:30:17 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Fixed.hpp"
#include	<iostream>
#include	<cmath>

Fixed::Fixed( void ){
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed( Fixed const &origin ){
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed::Fixed( int const num ){
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = num << this->fraction;
}

Fixed::Fixed( float const num ){
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(num * (1 << this->fraction));
}

Fixed &Fixed::operator=( Fixed const &origin ){
	std::cout << "Copy assaignment operator called" << std::endl;
	this->fixed_point = origin.getRawBits();
	return *this;
}

Fixed::~Fixed( void ){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const{
	return this->fixed_point;
}

void	Fixed::setRawBits( int const raw ){
	this->fixed_point = raw;
}

float	Fixed::toFloat( void ) const{
	return (float)this->getRawBits() / (1 << fraction);
}

int	Fixed::toInt( void ) const{
	return this->getRawBits() >> fraction;
}

std::ostream &operator<<( std::ostream &os, Fixed const &fixed ){
	os << fixed.toFloat();
	return os;
}
