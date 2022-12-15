/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:28:48 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/15 12:14:51 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Span.hpp"

#include	<iostream>
#include	<algorithm>
#include	<numeric> // 수치 알고리즘
// vector size 메모리 안의 요소 개수
// vector capacity 할당된 메모리의 크기
// vector resize ?

Span::Span( void ){
	this->_max = 0;
}

Span::Span( unsigned int n ){
	this->_max = n; // resize ?
}

Span::Span( Span const &origin ){
	Span::operator=(origin);
}

Span::~Span( void ){}

Span &Span::operator=( Span const &origin ){
	this->_max = origin._max;
	this->_vect = origin._vect; //? 알아서 복사 해주것지?
	return *this;
}

void	Span::addNumber( int value ){
	if (this->_max - this->_vect.size() < 0) // ?
		throw Span::FullOfNumbersException();
	this->_vect.push_back(value);
}


void	Span::addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end ){
	std::vector<int> add_range(begin, end); // ?
	if (this->_max - this->_vect.size() < add_range.size()) // 가능한가 불가능한가
		throw std::out_of_range("Full Max Exception"); //???????? exception 통일하기

	this->_vect.insert(this->_vect.end(), begin, end); // ? 두번 붙여쓰기한다는 단점이 있다.
}

int	Span::shortestSpan( void ) {
	if(this->_vect.size() <= 1)
		throw Span::LackOfNumbersException();

	// 오름차순으로 된다면 adj~ 에서 뒤의요소 - 앞의요소 하기 때문에 괜찮나 체크필요 아니라면 abs 사용
	std::vector<int> span(this->_vect.size());
	std::sort(this->_vect.begin(), this->_vect.end());
	std::adjacent_difference(this->_vect.begin(), this->_vect.end(), span.begin());

	return *std::min_element(++(span.begin()), span.end()); // 맨 첫번째 요소는 빼고 검사
}

int	Span::longestSpan( void ) const{
	int	max = *std::max_element(this->_vect.begin(), this->_vect.end()); // just std::min도 있음 먼차이
	int	min = *std::min_element(this->_vect.begin(), this->_vect.end());
	
	std::cout << max << " - " << min << " = " << max - min << std::endl;
	return max - min;
}

void	Span::printAll( void ) const{
	for ( std::vector<int>::const_iterator it = this->_vect.begin(); \
			it < this->_vect.end() ; it++ )
	{
		std::cout << *it << std::endl;
	}
}

const char	*Span::FullOfNumbersException::what() const throw(){
	return "Full Element Exception"; // 작명
}

const char	*Span::LackOfNumbersException::what() const throw(){
	return "Lack Element Exception";
}

// std::out_of_range();
