/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:00:46 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/15 11:46:27 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"MutantStack.hpp"
#include	<iostream>
#include	<stack>
#include	<list>
#include	<vector>

int main()
{

	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "----------- print mstack ... -----------" << std::endl;
		std::cout << mstack.top() << std::endl; // cout 17

		mstack.pop(); // pop 17
		std::cout << mstack.size() << std::endl; // cout 1;

		mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << *(++it) << std::endl; // second element 3
		std::cout << *(--it) << std::endl; // first element 5

		std::cout << "----------- print mstack, from begin to end -----------" << std::endl;
		while (it != ite) {
			std::cout << *it << std::endl; // 5, 3, 5, 737
			++it;
		}

		std::stack<int> s(mstack);
		std::cout << "----------- pop stack s -----------" << std::endl;
		while (!s.empty()) {
			std::cout << s.top() << std::endl; // 5, 3, 5, 737
			s.pop();
		}

		std::stack<int> sss;
		sss = mstack;
		std::cout << "----------- pop stack sss -----------" << std::endl;
		while (!sss.empty()) {
			std::cout << sss.top() << std::endl; // 5, 3, 5, 737
			sss.pop();
		}

	}

	std::cout << std::endl;
	std::cout << "----------- compare list -----------" << std::endl;
	{
		MutantStack<char> my_stack;

		my_stack.push('a');
		my_stack.push('b');
		my_stack.push('c');

		MutantStack<char>::iterator my_iter_begin = my_stack.begin();
		MutantStack<char>::iterator my_iter_end = my_stack.end();

		std::list<char> my_list(my_iter_begin, my_iter_end);
		std::list<char>::iterator my_list_begin = my_list.begin();
		std::list<char>::iterator my_list_end = my_list.end();

		for (; my_iter_begin != my_iter_end; my_iter_begin++ , my_list_begin++)
		{
			std::cout << *my_iter_begin << ", " << *my_list_begin << std::endl;
		}
		
		my_iter_begin = my_stack.begin();
		for (; my_iter_begin <= my_iter_end; --my_iter_end , --my_list_end)
		{
			std::cout << *my_iter_end << ", " << *my_list_end << std::endl;
		}


		MutantStack<char>::reverse_iterator my_iter_rbegin = my_stack.rbegin();
		MutantStack<char>::reverse_iterator my_iter_rend = my_stack.rend();
	
		std::list<char>::reverse_iterator my_list_rbegin = my_list.rbegin();
		std::list<char>::reverse_iterator my_list_rend = my_list.rend();

		for (; my_iter_rbegin != my_iter_rend; my_iter_rbegin++)
		{
			std::cout << "mutantstack : "<< *my_iter_rbegin << std::endl;
		}

		for (; my_list_rbegin != my_list_rend; my_list_rbegin++)
		{
			std::cout << "mutantstack : "<< *my_list_rbegin << std::endl;
		}

	}

	std::cout << std::endl;
	std::cout << "----------- compare vector -----------" << std::endl;
	{
		MutantStack<std::string> my_stack;

		my_stack.push("hellllo");
		my_stack.push("nice to meet chu");
		my_stack.push("finsh fish fish");

		MutantStack<std::string>::const_iterator my_iter_begin = my_stack.begin();
		MutantStack<std::string>::const_iterator my_iter_end = my_stack.end();

		std::vector<std::string> my_vector(my_iter_begin, my_iter_end);
		std::vector<std::string>::const_iterator my_vector_begin = my_vector.begin();
		std::vector<std::string>::const_iterator my_vector_end = my_vector.end();

		for (; my_iter_begin != my_iter_end; my_iter_begin++)
		{
			std::cout << "mutantstack : " << *my_iter_begin << std::endl;
		}
		for (; my_vector_begin != my_vector_end; my_vector_begin++)
		{
			std::cout << "vector : " << *my_vector_begin << std::endl;
		}
		
		MutantStack<std::string>::const_reverse_iterator my_iter_rbegin = my_stack.rbegin();
		MutantStack<std::string>::const_reverse_iterator my_iter_rend = my_stack.rend();
	
		std::vector<std::string>::const_reverse_iterator my_vector_rbegin = my_vector.rbegin();
		std::vector<std::string>::const_reverse_iterator my_vector_rend = my_vector.rend();

		for (; my_iter_rbegin != my_iter_rend; my_iter_rbegin++)
		{
			std::cout << "mutantstack : "<< *my_iter_rbegin << std::endl;
		}

		for (; my_vector_rbegin != my_vector_rend; my_vector_rbegin++)
		{
			std::cout << "vector : " << *my_vector_rbegin << std::endl;
		}

	}

	return 0;
}
