/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 13:30:03 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Contact.hpp"

Contact::Contact( void ){}

Contact::~Contact( void ){}

void Contact::set_info(const std::string last, const std::string first,
						const std::string nick, const std::string phone){
	this->last_name = last;
	this->first_name = first;
	this->nick_name = nick;
	this->phone_number = phone;
}

std::string Contact::get_lastname( void ) const{
	return (this->last_name);
}

std::string Contact::get_firstname( void ) const{
	return (this->first_name);
}

std::string Contact::get_nickname( void ) const{
	return (this->nick_name);
}

std::string Contact::get_phonenumber( void ) const{
	return (this->phone_number);
}
