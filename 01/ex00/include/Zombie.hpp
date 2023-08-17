/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:25:11 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/17 10:46:42 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string name;

  public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	Zombie *newZombie(std::string name);
	void randomChump(std::string name);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
