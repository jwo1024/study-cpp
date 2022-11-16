/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:54:09 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/16 16:45:49 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char *argv[]){
	if (argc > 1)
	{
		for (int j = 1; j < argc; j++)
		{
			for (int i = 0; i < (int)std::strlen(argv[j]); i++)
				argv[j][i] = (char)std::toupper(argv[j][i]);
			std::cout << argv[j];
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
