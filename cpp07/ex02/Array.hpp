/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:55:23 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/14 09:59:15 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include	<exception>

template <typename T>
class Array{
private:
	T	*_array;
	unsigned int	_size;
public:
	Array( void );
	Array( unsigned int n ); // initialized by default. ?
	Array( Array const &origin );
	~Array( void );

	Array	&operator=( Array const &origin );
	T		&operator[]( unsigned int idx );
	T const	&operator[]( unsigned int idx ) const;

	unsigned int	size( void ) const;
	void			resetArray( unsigned int const len );

	class	WrongArangeException : public std::exception{
		const char* what() const throw();
	};
	class	EmptyArrayException : public std::exception{
		const char* what() const throw();
	};
};

# include "Array.tpp"

#endif
