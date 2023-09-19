#include <iostream>

class Base
{
  public:
	virtual ~Base()
	{
	}
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base	*generate(void)
{
	int	i;

	std::srand(time(NULL));
	i = std::rand() % 3;
	switch (i)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	default:
		return (nullptr);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != nullptr)
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B *>(p) != nullptr)
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C *>(p) != nullptr)
		std::cout << "Type: C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Type: A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "Type: B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "Type: C" << std::endl;
			}
			catch (std::exception &e)
			{
			}
		}
	}
}

int	main(void)
{
	Base	*base = generate();
	identify(base);
	identify(*base);
	return (0);
}
