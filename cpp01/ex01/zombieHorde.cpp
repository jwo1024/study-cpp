/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:33:35 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/18 16:31:51 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"
#include	<sstream>

#include	<iostream>

Zombie*    zombieHorde( int N, std::string name ){
	Zombie	*zhorde = new Zombie[N];
	std::stringstream ss;

	for (int i = 0; i < N; i++)
	{
		ss.str("");
		ss << i;
		zhorde[i].init_name(name + ss.str());
	}
	return (zhorde);
}
