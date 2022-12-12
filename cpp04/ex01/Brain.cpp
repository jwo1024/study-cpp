/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:38:21 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/12 10:24:38 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Brain.hpp"
#include	<iostream>

Brain::Brain( void ){
	std::cout << "Brain : default constructor called" << std::endl;
}

Brain::Brain( const Brain &origin ){
	std::cout << "Brain : copy constructor called" << std::endl;
	Brain::operator=(origin);
}

Brain::~Brain( void ){
	std::cout << "Brain : destructor called" << std::endl;
}

Brain	&Brain::operator=( const Brain &origin ){
	for (int i = 0; i < 100 ; i ++)
		this->ideas[i] = origin.ideas[i];
	return *this;
}

void	Brain::setIdea( const int &idx, std::string idea ){
	if (0 <= idx && idx < 100)
		this->ideas[idx] = idea;
}

std::string const	Brain::getIdea( const int &idx ) const{
	if (0 <= idx && idx < 100)
		return this->ideas[idx];
	else
		return "false";
}
