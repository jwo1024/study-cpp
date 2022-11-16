/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:45 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/16 18:46:09 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"PhoneBook.hpp"
#include	<iostream>
#include	<iomanip>

PhoneBook::PhoneBook() {
	this->cnt = 0;
}

// 실패시 정의 ?해야 하나 ?
// 입력 받고  
void	PhoneBook::add_contact(Contact new_contact) {
	contact[cnt] = new_contact;
	cnt++;
	if (cnt == 8)
		cnt = 0;
}

void	PhoneBook::search_contact(int index) {
	std::string str;

	if (index > 7) // 0 ~ 7
		return ;
//	PhoneBook::show_contact_info(index); // ?
	std::cout << std::setw(10) << std::right << index;
	str = contact[index].get_firstname();
	PhoneBook::show_contact_info(str);
	str = contact[index].get_lastname();
	PhoneBook::show_contact_info(str);
	str = contact[index].get_nickname();
	PhoneBook::show_contact_info(str);
	std::cout << std::endl;
}

void	PhoneBook::show_contact_info(std::string str)
{
	// str 존재하지 않을 때
	if (str.length() > 10) // 함수화 ? 
		str.replace(9, 1, ".");
	std::cout << std::setw(10) << std::right << str; //(std::setfill())
}

