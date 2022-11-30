/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:17:26 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 17:21:26 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"
#include	<iostream>

int	main( void ){
	Zombie	*zombie1;

	zombie1 = newZombie("Foo-dynamic");
	zombie1->announce();
	delete zombie1;

	randomChump("Foo-static");

	return 0;
}
