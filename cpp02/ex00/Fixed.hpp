/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/02 23:30:49 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

class Fixed{
private:
	int	fixed_point;
	const static int fraction = 8; // ? cosnt? 	
public:
	Fixed( void );
	Fixed( Fixed const &origin );
	Fixed &operator=( Fixed const &origin );
	~Fixed( void );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
