/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 01:12:53 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/13 12:23:52 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Convertor.hpp"
#include	<iostream>
#include	<string>

int	main( int argc, char *argv[] ){
	if (argc != 2)
	{
		std::cout << "wrong argc" << std::endl;
		return 0;
	}
	Convertor	con;
	con.setValue(argv[1]);
	con.printValue();
	
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
