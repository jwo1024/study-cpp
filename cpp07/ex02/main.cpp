/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:55:23 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/14 09:59:15 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
	//	std::cout << mirror[i] << " " <<  numbers[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    return 0;
}

/* ------ MY TEST ------ */

// int	main( void ){

// 	try{
// 		Array< Array<int> > a(10);

// 		a[0].resetArray(10);
// 		a[1].resetArray(5);
// 		a[2].resetArray(100);

// 		(a[0])[0] = 10;
// 		(a[0])[1] = 20;
// 		(a[1])[0] = 1;
// 		(a[2])[1] = 2;

// 		std::cout << "\n a.get : " << std::endl;
// 		std::cout << (a[0])[0] << std::endl;
// 		std::cout << (a[0])[1] << std::endl;
// 		std::cout << (a[1])[0] << std::endl;
// 		std::cout << (a[2])[1] << std::endl;

// 		std::cout << " a.size : " << std::endl;
// 		std::cout << a[0].size() << std::endl;
// 		std::cout << a[1].size() << std::endl;
// 		std::cout << a[2].size() << std::endl;

// 		Array< Array<int> > b(10);
// 		std::cout << (b[2])[1] << std::endl;

// 	}
// 	catch (std::exception &e){
// 		std::cout << e.what() << std::endl;
// 	}

// 	try{
// 		Array<std::string> b(10);
// 		Array<std::string> c(1);

// 		b[0] = "Hello";
// 		b[1] = "nice to meet you";

// 		std::cout << "\n b.get : " << std::endl;
// 		std::cout << b[0] << std::endl;
// 		std::cout << b[1] << std::endl;

// 		std::cout << " b.size : " << std::endl;
// 		std::cout << b.size() << std::endl;

// 	//	std::cout << " b.get : " << std::endl;
// 	//	std::cout << b[100] << std::endl;

// 		c = b;
// 		std::cout << "\n c.get : " << std::endl;
// 		std::cout << c[0] << std::endl;
// 		std::cout << c[1] << std::endl;

// 		std::cout << " c.size : " << std::endl;
// 		std::cout << c.size() << std::endl;

// 		std::cout << " c.get : " << std::endl;
//  		std::cout << c[10] << std::endl;
// 	}
// 	catch (std::exception &e){
// 		std::cout << e.what() << std::endl;
// 	}

// 	return 0;
// }
