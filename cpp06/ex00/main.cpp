/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 01:12:53 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/12 10:43:10 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<string>

int	main( int argc, char *argv[] ){
	if (argc != 2)
	{
		std::cout << "wrong argc" << std::endl;
		return 0;
	}

	std::string	str = argv[1];
	std::cout << "str: " << str << std::endl;

	char	c = 0;
//	int		i = 0;
	float	f = 0;
	double	d = 0;

	

	try{

		c = static_cast<char>(std::stoi(argv[1]));
		if (c == 0)
			throw "Non displayable";
		std::cout << "char: " << c << std::endl; // Non displayable ?
	}
	catch(char const *str){
		std::cout << "char: " << str << '\n';
	}
	catch(const std::exception& e){
		std::cerr << "char: " << e.what() << '\n';
	}
	catch(...){
		std::cout << "char: impossible" << std::endl;
	}

	int i = 0;
	try{
		i = std::stoi(argv[1]);
		std::cout << "int: " << i << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "int: " << e.what() << '\n';
	}
	catch(...){
		std::cout << "int: impossible" << std::endl;
	}
	
	char	*endl;

	d = strtod(argv[1], &endl);
	printf("endl %c\n", *endl);
	f = static_cast<float>(d);
	i = static_cast<int>(d);
//	f = static_cast<float>(d);


//	std::cout << "char: " << c <<  std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;

	return 0;
}


// 범위 벗어났을때
// 출력되지 않는 문자일때
//

/*

먼저 타입을 확인하고,
string을 해당 타입으로 변환하고,
나머지 타입으로 변환한다.



*/
