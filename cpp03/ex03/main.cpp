/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:46:50 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 23:08:26 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"DiamondTrap.hpp"
#include	<iostream>

int	main ( void ){
	std::cout << std::endl << "------------------- DiamondTrap ---------------------" << std::endl;
	{
		DiamondTrap	a("bot1");
		DiamondTrap	b("bot2");
		DiamondTrap	c = a;
		DiamondTrap	d;

		std::cout << std::endl;
		a.whoAmI();
		c.whoAmI();
	
		std::cout << std::endl;
		a.attack( "target1" );
		a.takeDamage( 5 );
		a.beRepaired( 3 );
		a.hiFivesGuys();
		a.guardGate();

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
