/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/17 19:16:36 by jiwolee          ###   ########seoul.kr  */
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
 public: 
	Contact();
	Contact(std::string	last_name,
			std::string	first_name,
			std::string	nick_name,
			std::string	phone_number);
	void	set_info(std::string last_name,
			std::string	first_name,
			std::string	nick_name,
			std::string	phone_number);
	std::string get_lastname();
	std::string get_firstname();
	std::string get_nickname();
	std::string get_phonenumber();
	~Contact();
};

#endif
