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

#include	<iostream>

template <typename T>
class Array{
private:
	T[] _array;
public:
	Array( void );
	Array( size_t n );
	Array( Array const &origin );
	~Array( void );

	Array &operator=( Array const &origin );

	
	
};


#endif
