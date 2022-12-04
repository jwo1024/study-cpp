/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:19 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 10:58:21 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Point.hpp"
#include	<iostream>

int main( void ) {
	Point	a(-7, 3);
	Point	b(-2, -4);
	Point	c(2, 4);
	Point	p1(-2.7884693940916, 1.8179033455979);
	Point	p2(2, 4);

	std::cout << "triangle a x = " << a.getX() << " y = " << a.getY() << std::endl;
	std::cout << "triangle b x = " << b.getX() << " y = " << b.getY() << std::endl;
	std::cout << "triangle c x = " << c.getX() << " y = " << c.getY() << std::endl;
	std::cout << "Point p1 x = " << p1.getX() << " y = " << p1.getY() << std::endl;
	std::cout << "Point p2 x = " << p2.getX() << " y = " << p2.getY() << std::endl;

	if (bsp(a, b, c, p1))
		std::cout << "point p1 is in the triangle" << std::endl;
	else
		std::cout << "point p1 is out of the triangle" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "point p2 is in the triangle" << std::endl;
	else
		std::cout << "point p2 is out of the triangle" << std::endl;

	return 0; 
}
