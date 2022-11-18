/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:17:26 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/18 17:14:48 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"
#include	<iostream>

int	main( void ){
	Zombie	*zhorde;

	zhorde = zombieHorde(10, "zombie");
	
	for (int i = 0; i < 10; i++)
		zhorde[i].announce();
	delete[] zhorde;
	return 0;
}
