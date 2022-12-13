/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:33 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/13 14:52:20 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTOR_HPP
# define CONVERTOR_HPP

#include	<string>

class Convertor{
private:
	char	char_v;
	int		int_v;
	float	float_v;
	double	double_v;

	bool	is_char;
	bool	is_int;
	bool	is_float;
	bool	is_double;

	bool	impossible_all;
	bool	int_overflow;
	bool	char_overflow;

	void	detect_number( std::string &str );
	bool	detect_char( std::string &str );
	void	setCharValue( std::string &str );
	void	setIntValue( std::string &str );
	void	setFloatValue( std::string &str );
	void	setDoubleValue( std::string &str );

	void	printCharValue( void ) const;
	void	printIntValue( void ) const;
	void	printFloatValue( void ) const;
	void	printDoubleValue( void ) const;

public:
	Convertor( void );
	Convertor( Convertor const &origin );
	Convertor( char const *origin );
	~Convertor( void );

	Convertor	&operator=( Convertor const &origin );

	void	setValue( char const *str );
	void	printValue( void ) const;
};

#endif
