/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:45 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/24 20:44:14 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define	PHONEBOOK_HPP

# include	"Contact.hpp"

class PhoneBook
{
 private:
	Contact	contact[8];
	int		cnt;
	void	cout_info(std::string str);
 public:
	PhoneBook();
	void	add_contact(Contact contact);
	void	search_contact(int index);
	~PhoneBook();
};

#endif
