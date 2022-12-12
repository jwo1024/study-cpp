/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:33 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/12 11:47:43 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTOR_HPP
# define CONVERTOR_HPP

class Convertor{
private:
	double	value;
	bool	char_impossible;
	bool	char_non_displayable;
	bool	int_impossible;
	bool	float_impossible;
	bool	double_impossible;
	
	bool	not_a_number;

public:
	Convertor( void );
	Convertor( Convertor const &origin );
	Convertor( char const *origin );
	~Convertor( void );

	Convertor	&operator=( Convertor const &origin );

	void	setValue( char const *str );
	void	printCharValue( void ) const;
	void	printIntValue( void ) const;
	void	printFloatValue( void ) const;
	void	printDoubleValue( void ) const;
};

#endif