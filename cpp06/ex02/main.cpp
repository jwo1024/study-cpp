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
#include	"A.hpp"
#include	"B.hpp"
#include	"C.hpp"

#include	<cstdlib>
#include	<ctime>
#include	<iostream>

Base	*generate( void ){
	int	num;

	srand(time(NULL));
	num = rand() % 3;
	if (num == 0)
		return new A;
	else if (num == 1)
		return new B;
	else
		return new C;
}

void	identify( Base* p ){

	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "* type : A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "* type : B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "* type : C" << std::endl;

}

void	identify( Base& p ){
	try{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "& type : A" << std::endl;
		return;
	}
	catch (std::exception &e){
		std::cout << "	not type : A" << std::endl;
	}
	try{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "& type : B" << std::endl;
		return;
	}
	catch (std::exception &e){
		std::cout << "	not type : B" << std::endl;
	}
	try{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "& type : C" << std::endl;
		return;
	}
	catch (std::exception &e){
		std::cout << "	not type : C" << std::endl;
	}
}

int	main ( void ){
	Base	*base;

	base = generate();
	identify(*base);
	std::cout << std::endl;
	identify(base);

	return 0;
}
