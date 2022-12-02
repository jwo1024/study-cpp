/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:45:54 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/02 23:30:57 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Fixed.hpp"
#include	<iostream>

Fixed::Fixed( void ){
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed( Fixed const &origin ){
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
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
	std::cout << "getRawBits memeber function called" << std::endl;
	return this->fixed_point;
}

void	Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits memeber function called" << std::endl;
	this->fixed_point = raw;
}
