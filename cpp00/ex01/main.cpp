/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:59:28 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/24 20:34:33 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"PhoneBook.hpp"
#include	<iostream>

int		get_string_cin(std::string *str);
int 	get_int_cin(int	*num);
void	search_contact(PhoneBook *phone_book);
void	add_contact(PhoneBook *phone_book);

int	main(void)
{
	std::string	cmd;
	PhoneBook	phone_book;

	std::cout << "MY AWSOME PHONEBOOK" << std::endl;
	while (1)
	{
		std::cout << "enter 'ADD' or 'SERACH' or 'EXIT' : ";
	
		if (get_string_cin(&cmd) == -1)
			std::cout << "Fail cin, enter 'ADD' or 'SERACH' or 'EXIT'" << std::endl;
		else if (cmd.compare("ADD") == 0)
			add_contact(&phone_book);
		else if (cmd.compare("SEARCH") == 0)
			search_contact(&phone_book);
		else if (cmd.compare("EXIT") == 0)
		{
			std::cout << "Exit phone book! bye!" << std::endl;
			exit(0);
		}
		else
			std::cout << "Wrong input, enter 'ADD' or 'SERACH' or 'EXIT'" << std::endl;
	}
	return 0;
}

int	get_string_cin(std::string *str)
{
	if (str == NULL)
		return -1;
	std::cin >> *str;
	if (std::cin.eof())
	{
		std::cout << "Exit phone book! bye!" << std::endl;
		exit(0);
	}
	else if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}
	return 1;
}

int get_int_cin(int	*num)
{
	if (num == NULL)
		return -1;
	std::cin >> *num;
	if (std::cin.eof())
	{
		std::cout << "Exit phone book! bye!" << std::endl;
		exit(0);
	}
	else if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}
	return 1;
}

void	search_contact(PhoneBook *phone_book)
{
	int	idx;

	std::cout << "Search contact" << std::endl;
	std::cout << "searching index : ";
	if (get_int_cin(&idx) == -1)
	{
		std::cout << "Fail cin" << std::endl;
		return ;
	}
	phone_book->search_contact(idx);
}

void	add_contact(PhoneBook *phone_book)
{
	Contact	contact;
	std::string	last_name;
	std::string	first_name;
	std::string	nick_name;
	std::string	phone_number;

	std::cout << "ADD contact" << std::endl;
	std::cout << "last name : ";
	std::cin >> last_name;
	std::cout << "first name : ";
	std::cin >> first_name;
	std::cout << "nick name : ";
	std::cin >> nick_name;
	std::cout << "phone number : ";
	std::cin >> phone_number;
	contact.set_info(last_name, first_name, nick_name, phone_number);
	phone_book->add_contact(contact);
}
