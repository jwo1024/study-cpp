/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:34:50 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/04 17:02:57 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include	<string>

class Brain{
protected:
	std::string	ideas[100];
public:
	Brain( void );
	Brain( const Brain &origin );
	virtual ~Brain( void );

	Brain	&operator=( const Brain &origin );

	void		setIdea( const int &idx, std::string idea );
	std::string	getIdea( const int &idx ) const;

};

#endif
