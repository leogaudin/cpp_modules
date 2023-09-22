#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <list>

class Span
{
  public:
	Span(unsigned int n);
	Span(const Span &span);
	Span &operator=(const Span &span);
	~Span();
	void addNumber(int n);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();

  private:
	unsigned int size;
	std::vector<int> array;
};

#endif
