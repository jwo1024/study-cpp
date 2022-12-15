/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:48:03 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/15 11:13:53 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include	<stack>

template <typename T>
class MutantStack : public std::stack<T>{
public:
	MutantStack( void ){};
	MutantStack( MutantStack const &origin ){ *this = origin; };
	~MutantStack( void ){};

	MutantStack &operator=( MutantStack const &origin ){ *this = origin; return *this; };

	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;

	iterator	begin( void ){ return this->c.begin(); };
	const_iterator begin( void ) const{ return this->c.begin(); };
	iterator	end( void ){ return this->c.end(); };
	const_iterator end( void ) const{ return this->c.end(); };
	reverse_iterator rbegin( void ){ return this->c.rbegin(); };
	const_reverse_iterator rbegin( void ) const{ return this->c.rbegin(); };
	reverse_iterator rend( void ){ return this->c.rend(); };
	const_reverse_iterator rend( void ) const{ return this->c.rend(); };

};

#endif
