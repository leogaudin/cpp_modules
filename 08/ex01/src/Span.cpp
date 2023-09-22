#include "../include/Span.hpp"

Span::Span(unsigned int n): size(n)
{
	// std::cout << "Span: Default constructor called" << std::endl;
}

Span::~Span()
{
	// std::cout << "Span: Destructor called" << std::endl;
}

Span::Span(const Span &span)
{
	// std::cout << "Span: Copy constructor called" << std::endl;
	*this = span;
}

Span &Span::operator=(const Span &span)
{
	// std::cout << "Span: Copy assignment operator called" << std::endl;
	if (this != &span)
	{
		this->size = span.size;
		this->array = span.array;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->array.size() == this->size)
		throw std::exception();
	this->array.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->array.size() + std::distance(begin, end) > this->size)
		throw std::exception();
	this->array.insert(this->array.end(), begin, end);
}

int Span::shortestSpan()
{
	if (this->array.size() < 2)
		throw std::exception();
	std::vector<int> sorted(this->array);
	std::sort(sorted.begin(), sorted.end());
	int min = sorted[1] - sorted[0];
	for (unsigned int i = 2; i < sorted.size(); i++)
	{
		if (sorted[i] - sorted[i - 1] < min)
			min = sorted[i] - sorted[i - 1];
	}
	return (min);
}

int Span::longestSpan()
{
	if (this->array.size() < 2)
		throw std::exception();
	std::vector<int> sorted(this->array);
	std::sort(sorted.begin(), sorted.end());
	return (sorted[sorted.size() - 1] - sorted[0]);
}
