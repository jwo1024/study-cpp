/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:47:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/13 15:51:39 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Base.hpp"
#include	<cstdlib>
#include	<ctime>

Base	*generate( void ){
	int	num;

	srand(time(NULL));
	num = rand() % 3;
	if (num == 0)
		;
	else if (num == 1)
		;
	else
		;
}

void	identify( Base* p ){
	;
}

void	identify( Base& p ){
	;
}

int	main ( void ){
	;
	return 0;
}