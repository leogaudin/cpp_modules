#include <iostream>
#include <sstream>
#include <stack>
#include <string>

double	evaluateRPN(const std::string &expr)
{
	double	b;
	double	a;
	double	num;

	std::stack<double> stack;
	std::istringstream iss(expr);
	std::string token;
	while (iss >> token)
	{
		try
		{
			if (token == "(" || token == ")")
				throw std::runtime_error("Invalid expression");
			else if (token == "+" || token == "-" || token == "*"
					|| token == "/")
			{
				if (stack.size() < 2)
					throw std::runtime_error("Invalid expression");
				b = stack.top();
				stack.pop();
				a = stack.top();
				stack.pop();
				if (token == "+")
					stack.push(a + b);
				else if (token == "-")
					stack.push(a - b);
				else if (token == "*")
					stack.push(a * b);
				else if (token == "/")
					stack.push(a / b);
			}
			else
			{
				num = std::stod(token);
				stack.push(num);
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return (-1);
		}
	}
	return (stack.top());
}

int	main(int argc, char const *argv[])
{
	double	result;

	if (argc == 2)
	{
		result = evaluateRPN(argv[1]);
		if (result != -1)
			std::cout << result << std::endl;
	}
	else
		std::cout << "Usage: ./rpn [expression]" << std::endl;
	return (0);
}
