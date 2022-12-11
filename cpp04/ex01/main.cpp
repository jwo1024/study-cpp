/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:56:04 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 18:13:12 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Cat.hpp"
#include	"Dog.hpp"

#include	<iostream>

int	main( void ){
	{
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();

		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		Dog	dog1;
		dog1.setIdea(0, "first-idea");
		dog1.setIdea(1, "second-idea");
		dog1.setIdea(2, "third-idea");

		Dog	dog2(dog1);
		dog2.setIdea(0, "hi");

		std::cout << dog1.getIdea(0) << std::endl;
		std::cout << dog1.getIdea(1) << std::endl;
		std::cout << dog1.getIdea(2) << std::endl;
		std::cout << dog2.getIdea(0) << std::endl;
		std::cout << dog2.getIdea(1) << std::endl;
		std::cout << dog2.getIdea(2) << std::endl;

		Cat	cat1;
		;
	}
//	system("leaks a.out");
	return 0;
}
