/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:45:54 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 11:54:40 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Fixed.hpp"
#include	<iostream>
#include	<cmath>

Fixed::Fixed( void ){
	this->fixed_point = 0;
}

Fixed::Fixed( Fixed const &origin ){
	*this = origin;
}

Fixed::Fixed( int const num ){
	this->fixed_point = num << this->fraction;
}

Fixed::Fixed( float const num ){
	this->fixed_point = roundf(num * (1 << this->fraction));
}

Fixed	&Fixed::operator=( Fixed const &origin ){
	this->fixed_point = origin.getRawBits();
	return *this;
}

Fixed::~Fixed( void ){}

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

/* member func operator overloading */

bool	Fixed::operator>( Fixed const &fixed ) const{
	return this->fixed_point > fixed.getRawBits();
}

bool	Fixed::operator<( Fixed const &fixed ) const{
	return this->fixed_point < fixed.getRawBits();
}

bool	Fixed::operator>=( Fixed const &fixed ) const{
	return this->fixed_point >= fixed.getRawBits();
}

bool	Fixed::operator<=( Fixed const &fixed ) const{
	return this->fixed_point <= fixed.getRawBits();
}

bool	Fixed::operator==( Fixed const &fixed ) const{
	return this->fixed_point == fixed.getRawBits();
}

bool	Fixed::operator!=( Fixed const &fixed ) const{
	return this->fixed_point != fixed.getRawBits();
}

Fixed	Fixed::operator+( Fixed const &fixed ) const{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-( Fixed const &fixed ) const{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*( Fixed const &fixed ) const{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/( Fixed const &fixed ) const{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed	&Fixed::operator++( void ){
	this->fixed_point += 1;
	return *this;
}

Fixed	&Fixed::operator--( void ){
	this->fixed_point -= 1;
	return *this;
}

Fixed const	Fixed::operator++( int ){
	Fixed	tmp(*this);
	this->fixed_point += 1;
	return tmp;
}

Fixed const	Fixed::operator--( int ){
	Fixed	tmp(*this);
	this->fixed_point -= 1;
	return tmp;
}


/* static member func operator overloading */

Fixed &Fixed::max( Fixed &fixed1, Fixed &fixed2 ){
	if (fixed1 >= fixed2)
		return fixed1;
	return fixed2;
}

Fixed &Fixed::min( Fixed &fixed1, Fixed &fixed2 ){
	if (fixed1 <= fixed2)
		return fixed1;
	return fixed2;
}

Fixed const &Fixed::max( Fixed const &fixed1, Fixed const &fixed2 ){
	if (fixed1 >= fixed2)
		return fixed1;
	return fixed2;
}

Fixed const &Fixed::min( Fixed const &fixed1, Fixed const &fixed2 ){
	if (fixed1 <= fixed2)
		return fixed1;
	return fixed2;
}
