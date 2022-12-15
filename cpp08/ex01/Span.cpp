/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:28:48 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/15 21:53:42 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Span.hpp"

#include	<iostream>
#include	<algorithm>
#include	<numeric>

Span::Span( void ){
	this->_max = 0;
}

Span::Span( size_t n ){
	this->_max = n;
	this->_vect.reserve(n);
}

Span::Span( Span const &origin ){
	Span::operator=(origin);
}

Span::~Span( void ){}

Span &Span::operator=( Span const &origin ){
	this->_max = origin._max;
	this->_vect = origin._vect;
	this->_vect.reserve(this->_max);
	return *this;
}

void	Span::addNumber( int value ){
	if (this->_max <= this->_vect.size())
		throw Span::CanNotAddNumbersException();
	this->_vect.push_back(value);
}

int	Span::shortestSpan( void ) {
	if(this->_vect.size() <= 1)
		throw Span::LackOfNumbersException();
	std::vector<int> span(this->_vect.size());
	std::sort(this->_vect.begin(), this->_vect.end());
	std::adjacent_difference(this->_vect.begin(), this->_vect.end(), span.begin());
	return *std::min_element(++(span.begin()), span.end());
}

int	Span::longestSpan( void ) const{
	if(this->_vect.size() <= 1)
		throw Span::LackOfNumbersException();
	int	max = *std::max_element(this->_vect.begin(), this->_vect.end());
	int	min = *std::min_element(this->_vect.begin(), this->_vect.end());	
	return max - min;
}

void	Span::printAll( void ) const{
	for ( std::vector<int>::const_iterator it = this->_vect.begin(); \
			it < this->_vect.end() ; it++ )
	{
		std::cout << *it << std::endl;
	}
}

const char	*Span::CanNotAddNumbersException::what() const throw(){
	return "Can't add Numbers Exception";
}

const char	*Span::LackOfNumbersException::what() const throw(){
	return "Lack of Numbers Exception";
}
