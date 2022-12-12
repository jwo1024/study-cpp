/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:50:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 03:51:38 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Cat.hpp"
#include	<iostream>

Cat::Cat( void ){
	std::cout << "Cat : default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat( Cat const &origin ) : Animal(){
	std::cout << "Cat : copy constructor called" << std::endl;
	Cat::operator=(origin);
}

Cat::~Cat( void ){
	std::cout << "Cat : destructor called" << std::endl;
	delete	this->brain;
}

Cat	&Cat::operator=( Cat const &origin){
	this->type = origin.getType();
	*(this->brain) = *(origin.brain);
	return *this;
}

void	Cat::makeSound( void ) const{
	std::cout << "Cat : Meow~ Meow~" << std::endl;
}

Brain	*Cat::getBrain( void ) const{
	return this->brain;
}
