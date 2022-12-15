/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:29:08 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/15 21:56:57 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include	<vector>
#include	<exception>
#include	<cstddef>

class Span{
private:
	std::vector<int> _vect;
	size_t _max;
public:
	Span( void );
	Span( size_t n );
	Span( Span const &origin );
	~Span( void );

	Span &operator=( Span const &origin );

	void	addNumber( int value );

	template <typename C>
	void	addRange( typename C::iterator begin, typename C::iterator end ){
		if (this->_max - this->_vect.size() < static_cast<unsigned long>(std::distance(begin, end)))
			throw Span::CanNotAddNumbersException();
		this->_vect.insert(this->_vect.end(), begin, end);
	};

	int		shortestSpan( void ); 
	int		longestSpan( void ) const;

	void	printAll( void ) const;

	class CanNotAddNumbersException : public std::exception{
		public:
			const char *what() const throw();
	};
	class LackOfNumbersException : public std::exception{
		public:
			const char *what() const throw();
	};
};

#endif
