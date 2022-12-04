/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:46:50 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 15:42:42 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"FragTrap.hpp"
#include	<iostream>

int	main ( void ){
	std::cout << std::endl << "------------------- FragTrap ---------------------" << std::endl;
	{
		FragTrap	a("bot1");
		FragTrap	b("bot2");
		FragTrap	c = a;
		FragTrap	d;


		std::cout << std::endl;
		a.attack( "target1" );
		a.takeDamage( 5 );
		a.beRepaired( 3 );
		a.hiFivesGuys();

		std::cout << a.getName() << " [hit p: " << a.getHitPoints() \
					<< "], [energy p: " << a.getEnergyPoints() \
					<< "] [attack damage: " << a.getAttackDamage() << "]" << std::endl;

		std::cout << std::endl;
		b.attack( "target2" );
		b.takeDamage( 10 );
		b.beRepaired( 2 );
		b.attack( "target2" );
		b.hiFivesGuys();

		std::cout << b.getName() << " [hit p: " << b.getHitPoints() \
					<< "], [energy p: " << b.getEnergyPoints() \
					<< "] [attack damage: " << b.getAttackDamage() << "]" << std::endl;

		std::cout << std::endl;
		std::cout << c.getName() << " [hit p: " << c.getHitPoints() \
					<< "], [energy p: " << c.getEnergyPoints() \
					<< "] [attack damage: " << c.getAttackDamage() << "]" << std::endl;

		std::cout << std::endl;
		std::cout << d.getName() << " [hit p: " << d.getHitPoints() \
					<< "], [energy p: " << d.getEnergyPoints() \
					<< "] [attack damage: " << d.getAttackDamage() << "]" << std::endl;

		std::cout << std::endl;
	}
	return 0;
}
