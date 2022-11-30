/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 13:29:54 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define	CONTACT_HPP

# include	<string>

class Contact {
	std::string	last_name;
	std::string	first_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string get_phonenumber( void ) const;
public: 
	Contact( void );
	void	set_info(const std::string last_name,
					const std::string	first_name,
					const std::string	nick_name,
					const std::string	phone_number);
	std::string get_lastname( void ) const;
	std::string get_firstname( void ) const;
	std::string get_nickname( void ) const;
	~Contact( void );
};

#endif
