/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:46:50 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 15:32:50 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"ScavTrap.hpp"
#include	<iostream>

int	main ( void ){
	std::cout << std::endl << "------------------- ScavTrap ---------------------" << std::endl;
	{
		ScavTrap	a("bot1");
		ScavTrap	b("bot2");
		ScavTrap	c = a;
		ScavTrap	d;


		std::cout << std::endl;
		a.attack( "target1" );
		a.takeDamage( 5 );
		a.beRepaired( 3 );
		a.guardGate();

		std::cout << a.getName() << " [hit p: " << a.getHitPoints() \
					<< "], [energy p: " << a.getEnergyPoints() \
					<< "] [attack damage: " << a.getAttackDamage() << "]" << std::endl;

		std::cout << std::endl;
		b.attack( "target2" );
		b.takeDamage( 10 );
		b.beRepaired( 2 );
		b.attack( "target2" );
		b.guardGate();

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
