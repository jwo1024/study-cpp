/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/02 23:28:29 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

#include	<iostream>

class Fixed{
private:
	int	fixed_point;
	static int const fraction = 8;
public:
	Fixed( void );
	Fixed( Fixed const &origin );
	Fixed( int const num );
	Fixed( float const num );
	Fixed &operator=( Fixed const &origin);
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	bool operator>( Fixed const &fixed ) const;
	bool operator<( Fixed const &fixed ) const;
	bool operator>=( Fixed const &fixed ) const;
	bool operator<=( Fixed const &fixed ) const;
	bool operator==( Fixed const &fixed ) const;
	bool operator!=( Fixed const &fixed ) const;
	Fixed operator+( Fixed const &fixed ) const;
	Fixed operator-( Fixed const &fixed ) const;
	Fixed operator*( Fixed const &fixed ) const;
	Fixed operator/( Fixed const &fixed ) const;
	Fixed &operator++( void );
	Fixed &operator--( void );
	Fixed const operator++( int );
	Fixed const operator--( int );

	static Fixed const &max( Fixed &fixed1, Fixed &fixed2 );
	static Fixed const &min( Fixed &fixed1, Fixed &fixed2 );
	static Fixed const &max( Fixed const &fixed1, Fixed const &fixed2 );
	static Fixed const &min( Fixed const &fixed1, Fixed const &fixed2 );
};

std::ostream &operator<<( std::ostream &os, Fixed const &fixed );

#endif
