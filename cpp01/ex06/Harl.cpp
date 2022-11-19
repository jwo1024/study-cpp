/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:05:34 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/19 16:01:24 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Harl.hpp"
#include	<iostream>

Harl::Harl( void ){ }

Harl::~Harl( void ){ }

enum e_level	check_level( std::string level ){
	if (level.compare("DEBUG") == 0)
		return (L_DEBUG);
	else if (level.compare("INFO") == 0)
		return (L_INFO);
	else if (level.compare("WARNING") == 0)
		return (L_WARNING);
	else if (level.compare("ERROR") == 0)
		return (L_ERROR);
	else
		return L_DEFAULT;
}

void Harl::debug( void ){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
	std::cout <<  "I really do!" << std::endl << std::endl;
}

void Harl::info( void ){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void ){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void ){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void    Harl::complain( std::string level ){
	enum e_level	lev;

	lev = check_level(level);
	switch (lev)
	{
		case L_DEBUG:
			this->debug();
		case L_INFO:
			this->info();
		case L_WARNING:
			this->warning();
		case L_ERROR:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
 	}
}
