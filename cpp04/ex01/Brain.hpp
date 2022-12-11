/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:34:50 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 18:06:46 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include	<string>

class Brain{
private:
//protected:
	std::string	ideas[100];
public:
	Brain( void );
	Brain( const Brain &origin );
	~Brain( void );

	Brain	&operator=( const Brain &origin );

	void		setIdea( const int &idx, std::string idea );
	std::string const	getIdea( const int &idx ) const;
};

#endif
