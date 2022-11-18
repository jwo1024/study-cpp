/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:44:55 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/18 23:05:24 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HARL_HPP
# define	HARL_HPP

#include	<string>

enum	e_level{
	L_DEFAULT = 0,
	L_DEBUG = 1,
	L_INFO = 2,
	L_WARNING = 3,
	L_ERROR = 4
};

class Harl
{
private:
	/* data */
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl(/* args */);
	~Harl();
    void    complain( std::string level );
};




#include	<iostream>


Harl::Harl(/* args */){ }

Harl::~Harl(){ }

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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain( std::string level ){
	enum e_level	lev;

	lev = check_level(level);
	switch (lev)
	{
		case L_DEBUG:
			this->debug();
			break;
		case L_INFO:
			this->info();
			break;
		case L_WARNING:
			this->warning();
			break;
		case L_ERROR:
			this->error();
			break;
		default:
			break;
	}
}

#endif