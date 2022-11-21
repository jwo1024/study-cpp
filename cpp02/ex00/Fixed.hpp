/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/21 16:53:19 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int	fixed_point;
	const static int fraction = 8; // ? cosnt? 	
public:
	Fixed( void );
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &fixed);
	~Fixed( void );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
