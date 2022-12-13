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
#include	<iostream>

struct Data{
	std::string	data;
};

uintptr_t	serialize(Data* ptr){
	return	reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

int	main( void ){
	
	struct Data d;
	uintptr_t ptr;
	struct Data *d_ptr;

	d.data = "hello";
	
	ptr = serialize(&d);
	d_ptr = deserialize(ptr);

	std::cout << d_ptr->data << std::endl;
	std::cout << "d : " << &d << std::endl;
	std::cout << "d_ptr : " << d_ptr << std::endl;

	return 0;
}
