#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>

class RobotomyRequestForm : public Form
{
  public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyrequestform);
	~RobotomyRequestForm();
	void execute(Bureaucrat &bureaucrat) const;

  private:
	std::string const target;
};

#endif
