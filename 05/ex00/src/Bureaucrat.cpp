#include "../include/Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name), grade(grade)
{
	// std::cout << "Bureaucrat: Default constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat: Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	// std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	// std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
	this->grade = bureaucrat.grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat)
{
	output
		<< bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade();
	return (output);
}
