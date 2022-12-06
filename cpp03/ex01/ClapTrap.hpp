/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:46:48 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/06 17:21:22 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include	<string>

class ClapTrap{
protected:
	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	int				_attack_damage;
public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const &origin );
	virtual ~ClapTrap( void );

	ClapTrap	&operator=( ClapTrap const &origin );

	std::string		getName( void ) const;
	unsigned int	getHitPoints( void ) const;
	unsigned int	getEnergyPoints( void ) const;
	int				getAttackDamage( void ) const;

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};

#endif
