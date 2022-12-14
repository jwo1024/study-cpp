/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:55:23 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/14 09:59:15 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void ){
	this->_array = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::Array( unsigned int n ){
	this->_array = new T[n];
	this->_size = n;
}

template <typename T>
Array<T>::Array( Array const &origin ){
	this->_array = new T[origin._size];
}

template <typename T>
Array<T>::~Array( void ){
	if (this->_array)
		delete[] this->_array;
}


/* OPERATOR OVERLOADING */

template <typename T>
Array<T>	&Array<T>::operator=( Array<T> const &origin ){
	this->_size = origin._size;
	if (this->_array != NULL)
		delete[] this->_array;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = origin._array[i];
	return *this;
}

template <typename T>
T	&Array<T>::operator[]( unsigned int idx ){
	if (this->_array == NULL)
		throw Array<T>::EmptyArrayException();
	if (idx < this->_size)
		return this->_array[idx];
	else
		throw Array<T>::WrongArangeException();
}	

template <typename T>
const T	&Array<T>::operator[]( unsigned int const idx) const{
	if (this->_array == NULL)
		throw Array<T>::EmptyArrayException();
	if (idx < this->_size)
		return this->_array[idx];
	else
		throw Array<T>::WrongArangeException();
}


/* MEMBER FUNC */

template <typename T>
unsigned int	Array<T>::size( void ) const{
	return this->_size;
}

template <typename T>
void	Array<T>::resetArray( unsigned int const len ){
	if (this->_array != NULL)
		delete[] this->_array;
	this->_array = new T[len];
	this->_size = len;
}


/* EXCEPTION CLASS */

template <typename T>
const char* Array<T>::WrongArangeException::what() const throw(){
	return "Wrong Arange Exception";
}

template <typename T>
const char* Array<T>::EmptyArrayException::what() const throw(){
	return "Empty Array Exception";
}
