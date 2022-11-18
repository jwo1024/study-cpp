/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:17:26 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/18 15:32:06 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"
#include	<iostream>

int	main( void )
{
	Zombie	*zombie1;

	zombie1 = newZombie("Foo1");
	zombie1->announce();
	delete zombie1;

	randomChump("Foo2");
	return 0;
}
