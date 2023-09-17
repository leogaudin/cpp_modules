#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
  public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);
	~Bureaucrat();
	int getGrade() const;
	std::string getName() const;
	void incrementGrade();
	void decrementGrade();
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

  private:
	std::string const name;
	int grade;
};

std::ostream &operator<<(std::ostream &output,
							const Bureaucrat &bureaucreat);

#endif
