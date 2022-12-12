/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:27:45 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/12 12:22:21 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Convertor.hpp"
#include	<cstdlib>
#include	<iostream>

Convertor::Convertor( void ){
	this->value = 0;
	this->int_impossible = false;
	this->char_impossible = false;
}

Convertor::Convertor( Convertor const &origin ){
	Convertor::operator=(origin);
}

Convertor::Convertor( char const *str ){
	this->setValue(str);
}

Convertor::~Convertor( void ){}

Convertor	&Convertor::operator=( Convertor const &origin ){
	this->value = origin.value;
	this->int_impossible = origin.int_impossible;
	this->char_impossible = origin.char_impossible;
	this->char_non_displayable = origin.char_non_displayable;
	this->float_impossible = origin.float_impossible;
	this->double_impossible = origin.double_impossible;
}


void	Convertor::setValue( char const *str ){
	char *endptr;

	this->value = strtod(str, &endptr);
	if (this->value == 0 && *endptr)
	{
		;
	}
	if (*endptr && endptr != '\0') // 똑같은 의미 아닌가
	{
		//
	}
	//
}

void	Convertor::printCharValue( void ) const{
	char	c;

	if (char_impossible == true)
		std::cout << "char: impossible" << std::endl;
	else if (char_non_displayable == true)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		c = static_cast<char>(this->value);
		std::cout << "char: '" << c << "'" << std::endl;
	}
}

void	Convertor::printIntValue( void ) const{
	int	i;

	if (int_impossible == true)
		std::cout << "int: impossible" << std::endl;
	else
	{
		i = static_cast<int>(this->value);
		std::cout << "int: " << i << std::endl;
	}

}

void	Convertor::printFloatValue( void ) const{
	float f;
	
	if (float_impossible == true)
		std::cout << "float: impossible" << std::endl;
	else
	{
		f = static_cast<float>(this->value);
		std::cout << "float: " << f << "f" << std::endl;
	}
}

void	Convertor::printDoubleValue( void ) const{
	double	d;

	if (double_impossible == true)
		std::cout << "double: impossible" << std::endl;
	else
	{
		d = static_cast<double>(this->value);
	//	std::cout << std::fixed;
	//	std::cout.precision(6);


		std::cout << "double: " << d << std::endl;

		;// 실수부의 유무를 어떻게 알지?

	}
}




