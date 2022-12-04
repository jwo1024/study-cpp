/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:52:33 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 22:59:25 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCARVTRAP_HPP
# define SCARVTRAP_HPP

# include	"ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const &origin );
	~ScavTrap( void );

	ScavTrap	&operator=( ScavTrap const &origin );

	void	attack( const std::string& target );
	void	guardGate( void );
};

#endif
