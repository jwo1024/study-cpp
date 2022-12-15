/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:18:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/15 03:30:32 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

 #include	"Span.hpp"
 #include	<iostream>

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

//#include "Span.hpp"

#include <vector>

int main(){
	try{
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		Span an = Span(10000);

		an.addNumber(5);
		an.addNumber(3);
		an.addNumber(17);
		an.addNumber(9);
		an.addNumber(11);

		int test1[] = {1000, 29 , 243241, 5634532, 2, 3, 35, 566, 111, -4543, -32, -24};

	//	int test1[] = {10, 21, 4};

	//	std::vector<int> test1 {1000, 29 , 243241, 5634532, 2, 35, 566, 111, -4543, -32, -24};
	//	std::vector<int>test1 = { 1, 2, 3};
		std::vector<int> test2(test1, test1 + sizeof(test1)/sizeof(int));
		an.addRange(test2.begin(), test2.end());


	
		std::cout << an.shortestSpan() << std::endl;
		std::cout << an.longestSpan() << std::endl;
		


		std::cout << std::endl;
		an.printAll();		
		std::cout << std::endl;
	
	//	an.addNumber(42);
	}
	catch (std::exception & e){
		std::cout << "Oh no, error  " << e.what() << std::endl;
	}
}


