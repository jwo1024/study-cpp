/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:45 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 13:29:07 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define	PHONEBOOK_HPP

# include	"Contact.hpp"

class PhoneBook {
 private:
	Contact	contact[8];
	int		cnt;
	void	cout_info(std::string str) const;
 public:
	PhoneBook( void );
	void	add_contact(const Contact contact);
	void	search_contact(const int index) const;
	~PhoneBook( void );
};

#endif
