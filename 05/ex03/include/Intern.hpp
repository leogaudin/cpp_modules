#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
  public:
	Intern();
	Intern(const Intern &intern);
	Intern &operator=(const Intern &intern);
	~Intern();
	Form *makeForm(std::string form, std::string target);

  private:

};

#endif
