/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:56:04 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/12 10:22:45 by jiwolee          ###   ########seoul.kr  */
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
		Animal	*animals[10];

		for (int i = 0; i < 5; i++)
			animals[i] = new Cat;
		for (int i = 5; i < 10; i++)
			animals[i] = new Dog;

		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	std::cout << std::endl;
	{
		Cat	*cat1 = new Cat;
		Cat	*cat2 = new Cat(*cat1);
		Cat	*cat3 = new Cat;

		cat1->setIdea(0, "fish");
		cat1->setIdea(1, "catnip");
		cat1->setIdea(2, "nap");
		*cat3 = *cat2 = *cat1;
		std::cout << "type" << cat1->getType() << std::endl;

		std::cout << cat1->getIdea(0) << std::endl;
		std::cout << cat1->getIdea(1) << std::endl;
		std::cout << cat1->getIdea(2) << std::endl;
		std::cout << std::endl;
		std::cout << cat2->getIdea(0) << std::endl;
		std::cout << cat2->getIdea(1) << std::endl;
		std::cout << cat2->getIdea(2) << std::endl;
		std::cout << std::endl;
		std::cout << cat3->getIdea(0) << std::endl;
		std::cout << cat3->getIdea(1) << std::endl;
		std::cout << cat3->getIdea(2) << std::endl;
	
		delete cat1;
		delete cat2;
		delete cat3;
	}
	return 0;
}
