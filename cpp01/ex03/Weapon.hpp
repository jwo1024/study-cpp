/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:53:57 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/18 18:24:28 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
# define WEAPON_HPP

# include	<string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(/* args */);
	Weapon(std::string set_type);
	~Weapon();

	std::string getType();
	void setType(std::string set_type);
};

#endif
