/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:45:31 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/16 14:00:42 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;

  public:
	Contact();
	void create(void);
	std::string prompt(std::string prompt);
	void print(void);
	bool empty(void);
	std::string get_first_name(void);
	std::string get_last_name(void);
	std::string get_nickname(void);
};

#endif
