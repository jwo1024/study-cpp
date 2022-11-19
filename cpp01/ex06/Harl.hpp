/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:44:55 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/19 15:41:32 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HARL_HPP
# define	HARL_HPP

#include	<string>

enum	e_level{
	L_DEFAULT = 0,
	L_DEBUG = 1,
	L_INFO = 2,
	L_WARNING = 3,
	L_ERROR = 4
};

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl( void );
	~Harl( void );
    void    complain( std::string level );
};

#endif
