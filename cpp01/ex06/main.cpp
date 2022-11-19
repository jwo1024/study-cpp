/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:38:42 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/19 15:55:25 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Harl.hpp"
#include	<iostream>

int	main (int argc, char *argv[] ){
	Harl	harl;

	if (argc == 2)
		harl.complain(argv[1]);
	return 0;
}
