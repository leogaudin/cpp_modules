#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm: public Form
{
  public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialpardonform);
	~PresidentialPardonForm();
	void execute(Bureaucrat &bureaucrat) const;

  private:
	std::string const target;

};

#endif
