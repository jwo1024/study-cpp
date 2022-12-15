/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:18:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/15 22:07:42 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Span.hpp"
#include	<iostream>
#include	<vector>
#include	<ctime>
#include	<cstdlib>

// int main() {
// 	Span sp = Span(7);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	sp.addNumber(10000);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	sp.printAll();

// 	return 0; 
// }



int main(){

/*  test basic Span shortestSpan & longestSpan */
	std::cout << "\n---------- test basic Span shortestSpan & longestSpan ---------" << std::endl;
	try{
		/* sp */
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "sp shortestSpan : " << sp.shortestSpan() << std::endl;
		std::cout << "sp longestSpan : " << sp.longestSpan() << std::endl;

		/* an */
		Span an = Span(10000);

		an.addNumber(5);
		an.addNumber(3);
		an.addNumber(17);
		an.addNumber(9);
		an.addNumber(11);

		int test1[] = {1000, 29 , 243241, 5634532, 2, 35, 566, 111, -4543, -32, -24};
		std::vector<int> test2(test1, test1 + sizeof(test1)/sizeof(int));

		an.addRange< std::vector<int> >(test2.begin(), test2.end());
	
		std::cout << "an shortestSpan : "<< an.shortestSpan() << std::endl;
		std::cout << "an longestSpan : " << an.longestSpan() << std::endl;

		std::cout << "\n---------- check 'an = copy' work ---------" << std::endl;
		std::cout << "---------- an print all ---------" << std::endl;
		an.printAll();
		std::cout << "---------- copy print all ---------" << std::endl;
		Span copy = an;
		copy.printAll();
		std::cout << "---------- copy2 print all ---------" << std::endl;
		Span copy2(an);
		copy2.printAll();

	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

/* 100000 element  Check */
	std::cout << "\n---------- 100000 element  Check ---------" << std::endl;
	try{
		Span arr(100000);

		std::srand(std::time(NULL));
		for (size_t i = 0; i < 100000; i++)
		{
			arr.addNumber(std::rand() % 10000000);
		}
		std::cout << "finish add 100000 numbers" << std::endl;	
		std::cout << "arr shortestSpan : " << arr.shortestSpan() << std::endl;
		std::cout << "arr longestSpan : " << arr.longestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}


/* Exception Check */
	/* add Number exception */
	std::cout << "\n----------add Number exception ---------" << std::endl;
	try{
		Span sp = Span(4);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	/* add Range exception */
	std::cout << "\n---------- add Range exception ---------" << std::endl;
	try{
		Span an = Span(1);

		int test1[] = {1000, 29 , 243241, 5634532, 2, 3, 35, 566, 111, -4543, -32, -24};
		std::vector<int> test2(test1, test1 + sizeof(test1)/sizeof(int));
		an.addRange< std::vector<int> >(test2.begin(), test2.end());
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	/* shortestSpan exception */
	std::cout << "\n---------- shortestSpan exception ---------" << std::endl;
	try{
		Span an = Span(10);

		an.addNumber(11);
		std::cout << an.shortestSpan();
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	/* longestSpan exception */
	std::cout << "\n---------- longestSpan exception ---------" << std::endl;
	try{
		Span an = Span(10);

		an.addNumber(11);
		std::cout << an.longestSpan();
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
