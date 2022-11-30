/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:45 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 13:34:36 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"PhoneBook.hpp"
#include	<iostream>
#include	<iomanip>

PhoneBook::PhoneBook( void ){
	this->cnt = 0;
}

PhoneBook::~PhoneBook( void ){}

void	PhoneBook::add_contact(const Contact new_contact) {
	this->contact[cnt] = new_contact;
	cnt++;
	if (cnt == 8)
		cnt = 0;
}

void	PhoneBook::search_contact(const int index) const{
	std::string	str;

	if (index > 7 || index < 0)
	{
		std::cout << "Wrong index input" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << std::right << index << '|';
	str = this->contact[index].get_firstname();
	PhoneBook::cout_info(str);
	std::cout << '|';
	str = this->contact[index].get_lastname();
	PhoneBook::cout_info(str);
	std::cout << '|';
	str = this->contact[index].get_nickname();
	PhoneBook::cout_info(str);
	std::cout << std::endl;
}

void	PhoneBook::cout_info(std::string str) const{
	if (str.length() > 10)
	{
		str.replace(9, 1, ".");
		str.erase(str.begin() + 10, str.end());
	}
	std::cout << std::setw(10) << std::right << str;
}
