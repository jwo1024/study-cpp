/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:53:57 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 19:02:22 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
# define WEAPON_HPP

# include	<string>

class Weapon{
private:
	std::string	type;
public:
	Weapon( void );
	Weapon( std::string set_type );
	~Weapon( void );

	const std::string& getType( void ) const;
	void setType( std::string set_type );
};

#endif
