#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class	Bureaucrat;

class Form
{
  public:
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &form);
	Form &operator=(const Form &form);
	~Form();
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	virtual void execute(Bureaucrat &bureaucrat) const = 0;

  private:
	std::string const name;
	bool isSigned;
	int const gradeToSign;
	int const gradeToExecute;
};

std::ostream &operator<<(std::ostream &output,
							const Form &form);

#endif
