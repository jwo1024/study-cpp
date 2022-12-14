/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:08:28 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/14 09:47:09 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	my_print(T const &data){
	std::cout << "print " << data << std::endl;
}

template <typename T>
void	func(T &data){
	std::cout << "func " << data << std::endl;
}

template <typename T>
void	sqrt(T &data){
	data = data * data;
}



template <typename T>
void	iter(T const *arr, size_t const len, void (*func)(T const &)){
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void	iter(T *arr, size_t len, void (*func)(T &)){
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif
