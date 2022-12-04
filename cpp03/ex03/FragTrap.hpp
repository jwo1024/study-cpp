/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:52:33 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 22:58:36 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include	"ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( FragTrap const &origin );
	~FragTrap( void );

	FragTrap	&operator=( FragTrap const &origin );

	void	attack( const std::string& target );
	void	hiFivesGuys( void );
};

#endif
