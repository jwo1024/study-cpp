/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 01:32:24 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 11:35:25 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Point.hpp"

bool checkLine( Point const line1, Point const line2, Point const point){
	if ((line1.getY() < point.getY() && point.getY() < line2.getY()) || \
	 	(line2.getY() < point.getY() && point.getY() < line1.getY()))
	{
		Fixed	f1 = line1.getX() - line2.getX();
		Fixed	f2 = point.getY() - line2.getY();
		Fixed	f3 = line1.getY() - line2.getY();
		Fixed	fx = f1 * f2 / f3 + line2.getX();
		if (point.getX() < fx)
			return true;
	}
	return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point ){
	int	cnt = 0;
	
	if (checkLine(a, b, point))
		cnt++;
	if (checkLine(b, c, point))
		cnt++;
	if (checkLine(a, c, point))
		cnt++;

	if (cnt == 1)
		return true;
	else
		return false;
}
