/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:33:31 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/16 16:49:11 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "colors.h"
# include <iomanip>

class PhoneBook
{
  private:
	Contact contacts[8];

  public:
	PhoneBook();
	void startup(void);
	void add(void);
	void search(void);
	void shift_contacts(void);
	void get_contact_prompt(void);
};

#endif
