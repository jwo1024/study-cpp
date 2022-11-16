/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:45 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/16 18:33:07 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Contact.hpp"

class PhoneBook {
	Contact	contact[8];
	int		cnt;
 public:
	PhoneBook();

	void	add_contact(Contact contact);
	void	search_contact(int index);
	void	show_contact_info(std::string str);

	~PhoneBook();
};
