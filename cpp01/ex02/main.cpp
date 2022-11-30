/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:15:21 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 18:45:51 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>

int	main( void ){
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "address str: " << &str << std::endl;
	std::cout << "address PTR: " << stringPTR << std::endl;
	std::cout << "address REF: " << &stringREF << std::endl;

	std::cout << "value str: " << str << std::endl;
	std::cout << "value PTR: " << *stringPTR << std::endl;
	std::cout << "value REF: " << stringREF << std::endl;


	/* change REF value */
	stringREF = "hello";
	std::cout << "value str: " << str << std::endl;
	std::cout << "value PTR: " << *stringPTR << std::endl;
	std::cout << "value REF: " << stringREF << std::endl;

//	system("leaks hi_this_is_brain");

	return 0;
}
