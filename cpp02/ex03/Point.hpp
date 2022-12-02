/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 02:27:39 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_HPP
# define POINT_HPP

#include	"Fixed.hpp"

class Point{
private:
	Fixed const x_;
	Fixed const y_;
public:
	Point( void );
	Point( float const x, float const y );
	Point( Point const &origin );
	Point &operator=( Point const &origin );
	~Point( void );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
