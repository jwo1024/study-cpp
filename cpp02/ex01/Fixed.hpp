/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/21 17:12:18 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

#include	<iostream>

class Fixed
{
private:
	int	fixed_point;
	const static int fraction = 8; // ? cosnt? 
public:
	Fixed( void );
	Fixed(const Fixed &copy);
	Fixed(const int num);
	Fixed(const float num);
	Fixed &operator=(const Fixed &fixed);
	~Fixed( void );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
