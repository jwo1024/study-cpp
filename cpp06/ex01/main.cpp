/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:52:17 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/13 15:43:14 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	<string>

struct Data{
	std::string	str;
};

uintptr_t	serialize(Data* ptr){
	return	reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

int	main( void ){
	
	return 0;
}

