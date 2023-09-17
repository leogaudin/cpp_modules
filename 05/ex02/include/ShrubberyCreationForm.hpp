#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>

class ShrubberyCreationForm : public Form
{
  public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberycreationform);
	~ShrubberyCreationForm();
	void execute(Bureaucrat &bureaucrat) const;

  private:
	std::string const target;
};

#endif
