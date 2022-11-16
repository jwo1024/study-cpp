/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/16 17:44:32 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Contact.hpp"

Contact::Contact(std::string last, std::string	first,
					std::string	nick, std::string	phone) {
	this->last_name = last;
	this->first_name = first;
	this->nick_name = nick;
	this->phone_number = phone;
};

std::string Contact::get_lastname() {
	return (last_name);
};

std::string Contact::get_firstname() {
	return (first_name);
};

std::string Contact::get_nickname() {
	return (nick_name);
};

std::string Contact::get_phonenumber() {
	return (phone_number);
};
