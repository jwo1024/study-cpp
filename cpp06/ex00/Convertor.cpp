/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:27:45 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/13 14:38:53 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Convertor.hpp"
#include	<cstdlib>
#include	<iostream>
#include	<string>
#include	<limits>

#include	<cmath>

Convertor::Convertor( void ){
	this->char_v = 0;
	this->int_v = 0;
	this->float_v = 0;
	this->double_v = 0;
	this->is_char = false;
	this->is_int = false;
	this->is_float = false;
	this->is_double = false;
	this->is_string = false;

	this->impossible_all = false;
	this->int_overflow = false;
	this->char_overflow = false;
}

Convertor::Convertor( Convertor const &origin ){
	Convertor::operator=(origin);
}

Convertor::Convertor( char const *str ){
	this->char_v = 0;
	this->int_v = 0;
	this->float_v = 0;
	this->double_v = 0;
	this->is_char = false;
	this->is_int = false;
	this->is_float = false;
	this->is_double = false;
	this->is_string = false;

	this->impossible_all = false;
	this->int_overflow = false;
	this->char_overflow = false;
	this->setValue(str);
}

Convertor::~Convertor( void ){}

Convertor	&Convertor::operator=( Convertor const &origin ){
	this->char_v = origin.char_v;
	this->int_v = origin.int_v;
	this->float_v = origin.float_v;
	this->double_v = origin.double_v;
	this->is_char = origin.is_char;
	this->is_int = origin.is_int;
	this->is_float = origin.is_float;
	this->is_double = origin.is_double;
	this->is_string = origin.is_string;

	this->impossible_all = origin.impossible_all;
	this->int_overflow = origin.int_overflow;
	this->char_overflow = origin.char_overflow;
	return *this;
}


/* --- DETECT TYPES --- */

bool	Convertor::detect_char( std::string &str ){
	size_t	pos = 0;

	if (str[0] != '\0' && str[1] == '\0' \
		&& str.find_first_not_of("012345689", pos) == 0)
	{
		this->is_char = true;
		return true;
	}
	return false;
}

void	Convertor::detect_number( std::string &str ){
	size_t	pos = 0;

	if (str[pos] == '+' || str[pos] == '-')
		pos++;
	pos = str.find_first_not_of("0123456789", pos);
	if (pos == std::string::npos)
		this->is_int = true;
	else
	{
		if (str[pos] == '.')
		{
			pos = str.find_first_not_of("012345689", pos + 1);
			if (pos == std::string::npos)
				this->is_double = true;
			else if (str[pos] == 'f' && str[pos + 1] == '\0')
				this->is_float = true;
			else
			{
				this->impossible_all = true;
				this->is_string = true;
			}
		}
		else
		{
			if (str == "inf" || str == "-inf" || str == "+inf" || str == "nan")
				this->is_double = true;
			else if (str == "inff" || str == "-inff" || str == "+inff" || str == "nanf")
				this->is_float = true;
			else
			{
				this->impossible_all = true;
				this->is_string = true;
			}
		}
	}
}



/* --- SET VALUES --- */

void	Convertor::setValue( char const *str ){
	if (str == NULL)
	{
		std::cout << "Convertor : str is NULL" << std::endl;
		return;
	}

	std::string	s = str;
	bool	*is_types[5] = {&this->is_char, &this->is_int, &this->is_float, &this->is_double, &this->is_string};
	void	(Convertor::*set_funcs[4])(std::string &str) = {&Convertor::setCharValue, \
			&Convertor::setIntValue, &Convertor::setFloatValue, &Convertor::setDoubleValue};

	if (detect_char(s) == false)
		detect_number(s);
	if (*is_types[4] == true)
		std::cout << "type : string" << std::endl;
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (*is_types[i] == true)
			{
				std::cout << "type : " << i << std::endl;
				(this->*set_funcs[i])(s);
			}
		}
	}
}

void	Convertor::setCharValue( std::string &str ){
	this->char_v = str[0];

	this->int_v = static_cast<int>(this->char_v);
	this->float_v = static_cast<float>(this->char_v);
	this->double_v = static_cast<double>(this->char_v);
}

void	Convertor::setIntValue( std::string &str ){
	double d = strtol(str.c_str(), NULL, 10);
	if (d > static_cast<double>(std::numeric_limits<int>::max()) \
		|| d < static_cast<double>(std::numeric_limits<int>::min()))
	{
		this->impossible_all = true;
		this->int_overflow = true;
	}
	this->int_v = static_cast<int>(d);

	if (this->int_v > static_cast<int>(std::numeric_limits<char>::max()) \
		|| this->int_v < static_cast<int>(std::numeric_limits<char>::min()))
		this->char_overflow = true;
	else
		this->char_v = static_cast<int>(this->int_v);
	this->float_v = static_cast<float>(this->int_v);
	this->double_v = static_cast<double>(this->int_v);
}

void	Convertor::setFloatValue( std::string &str ){
	this->float_v = strtof(str.c_str(), NULL);

	if (this->float_v > static_cast<float>(std::numeric_limits<char>::max()) \
		|| this->float_v < static_cast<float>(std::numeric_limits<char>::min()))
		this->char_overflow = true;
	else
		this->char_v = static_cast<int>(this->float_v);
	if (this->float_v > static_cast<float>(std::numeric_limits<int>::max()) \
		|| this->float_v < static_cast<float>(std::numeric_limits<int>::min()))
		this->int_overflow = true;
	else
		this->int_v = static_cast<int>(this->float_v);
	this->double_v = static_cast<double>(this->float_v);
}

void	Convertor::setDoubleValue( std::string &str ){
	this->double_v = strtod(str.c_str(), NULL);

	if (this->double_v > static_cast<double>(std::numeric_limits<char>::max()) \
		|| this->double_v < static_cast<double>(std::numeric_limits<char>::min()))
		this->char_overflow = true;
	else
		this->char_v = static_cast<int>(this->double_v);
	if (this->double_v > static_cast<double>(std::numeric_limits<int>::max()) \
		|| this->double_v < static_cast<double>(std::numeric_limits<int>::min()))
		this->int_overflow = true;
	else
		this->int_v	= static_cast<int>(this->double_v);
	this->float_v	= static_cast<float>(this->double_v);
}


/* --- PRINT VALUES --- */

void	Convertor::printValue( void ) const{
	if (impossible_all == true)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else if (std::isnan(this->double_v)) // ? 적용이 안됨..  // float 는 ? 
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		this->printCharValue();
		this->printIntValue();
		this->printFloatValue();
		this->printDoubleValue();
	}
}

void	Convertor::printCharValue( void ) const{
	if (this->char_overflow == true)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(this->char_v) == 0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << this->char_v << "'" << std::endl;
}

void	Convertor::printIntValue( void ) const{
	if (this->int_overflow == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->int_v << std::endl;
}

void	Convertor::printFloatValue( void ) const{
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "float: " << this->float_v << "f" << std::endl;
}

void	Convertor::printDoubleValue( void ) const{
	std::cout << "double: " << this->double_v << std::endl;
}
