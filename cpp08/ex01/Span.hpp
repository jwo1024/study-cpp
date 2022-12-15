/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:29:08 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/15 02:29:13 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include	<vector>
#include	<exception>

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
	void	addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end );
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
