/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:56:04 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/04 17:57:36 by jiwolee          ###   ########seoul.kr  */
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
		Dog	*dog = new Dog();
		Brain	*brain = dog->getBrain();
		Dog	*dog2 = new Dog();
		Brain	*brain2 = dog2->getBrain();

		std::cout << std::endl;
		brain->setIdea(0, "first_idea");
		brain->setIdea(1, "second_idea");
		brain->setIdea(2, "third_idea");
		*dog2 = *dog;
		brain2->setIdea(0, "set_idea");


		std::cout << std::endl;
		std::cout << brain->getIdea(0) << std::endl;
		std::cout << brain->getIdea(1) << std::endl;
		std::cout << brain->getIdea(2) << std::endl;
		std::cout << brain2->getIdea(0) << std::endl;
		std::cout << brain2->getIdea(1) << std::endl;
		std::cout << brain2->getIdea(2) << std::endl;

		std::cout << (dog->getBrain()) << " " << (dog2->getBrain()) << std::endl;
		std::cout << std::endl;
		delete dog;
		delete dog2;
	}
	//system("leaks a.out");
	return 0;
}
