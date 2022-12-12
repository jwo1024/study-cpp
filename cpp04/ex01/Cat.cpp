/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:50:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/12 10:18:29 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Cat.hpp"
#include	<iostream>

Cat::Cat( void ){
	std::cout << "Cat : default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat( Cat const &origin ) : Animal(){
	std::cout << "Cat : copy constructor called" << std::endl;
	this->brain = new Brain();
	Cat::operator=(origin);
}

Cat::~Cat( void ){
	std::cout << "Cat : destructor called" << std::endl;
	if (this->brain)
		delete	this->brain;
}

Cat	&Cat::operator=( Cat const &origin){
	this->type = origin.type;
	*(this->brain) = *(origin.brain);
	return *this;
}

void	Cat::makeSound( void ) const{
	std::cout << "Cat : Meow~ Meow~" << std::endl;
}

Brain	*Cat::getBrain( void ) const{
	return this->brain;
}

std::string const	Cat::getIdea( int const idx ) const{
	return this->brain->getIdea(idx);
}

void	Cat::setIdea( int const idx, std::string const idea ){
	this->brain->setIdea(idx, idea);
}
