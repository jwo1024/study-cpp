/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:19 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 17:21:29 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

Zombie* newZombie( std::string name ){
	Zombie *newZombie = new Zombie(name);
	return (newZombie);
}
