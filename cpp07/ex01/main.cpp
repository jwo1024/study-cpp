/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:08:00 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/14 09:44:32 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"iter.hpp"
#include 	<iostream>
#include	<vector>


int main( void ){
	int	arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


	iter<int>(arr, 10, func);
 
	std::cout << std::endl;
	iter<int>(arr, 10, my_print);

	std::cout << std::endl;
	iter<int>(arr, 10, sqrt);
	iter<int>(arr, 10, my_print);

	return 0;
}
