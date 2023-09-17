#include "../include/Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form: grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form: grade too low");
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign),
		gradeToExecute(gradeToExecute)
{
	// std::cout << "Form: Parameter constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	// std::cout << "Form: Destructor called" << std::endl;
}

Form::Form(const Form &form)
	: name(form.getName()), isSigned(form.getIsSigned()),
		gradeToSign(form.getGradeToSign()),
		gradeToExecute(form.getGradeToExecute())
{
	// std::cout << "Form: Copy constructor called" << std::endl;
	*this = form;
}

Form &Form::operator=(const Form &form)
{
	// std::cout << "Form: Copy assignment operator called" << std::endl;
	this->isSigned = form.isSigned;
	return (*this);
}

std::string Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return (isSigned);
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	else
		isSigned = true;
}

std::ostream &operator<<(std::ostream &output, const Form &form)
{
	output << "Form \"" << form.getName() << "\"";
	return (output);
}
