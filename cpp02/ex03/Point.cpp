/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 11:38:11 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Point.hpp"

Point::Point( void ) : x_(0), y_(0){}

Point::Point( float const x, float const y ) : x_(x), y_(y){}

Point::Point( Point const &origin ) 
		: x_(origin.getX()), y_(origin.getY()){}

Point &Point::operator=( Point const &origin ) {
	const_cast<Fixed&>(this->x_) = origin.getX();
	const_cast<Fixed&>(this->y_) = origin.getY();
	return *this;
}

Point::~Point( void ){}

Fixed	Point::getX( void ) const{
	return x_;
}

Fixed	Point::getY( void ) const{
	return y_;
}
