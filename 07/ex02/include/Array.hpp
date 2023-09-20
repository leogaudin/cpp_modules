#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T>
class Array
{
  public:
	Array()
		: _n(0)
	{
		_array = new T[0];
	}
	Array(unsigned int n)
		: _n(n)
	{
		_array = new T[n];
	}
	Array(const Array &array)
	{
		*this = array;
	}
	Array &operator=(const Array &array)
	{
		if (this != &array)
		{
			_n = array._n;
			_array = new T[_n];
			for (unsigned int i = 0; i < _n; i++)
				_array[i] = array._array[i];
		}
		return (*this);
	}
	~Array()
	{
		delete[] _array;
	}
	T& operator[] (int index)
	{
		if (index < 0 || index >= static_cast<int>(_n))
		{
			std::cout << "Index out of range: ";
			throw std::exception();
		}
		return _array[index];
	}

  private:
	unsigned int _n;
	T *_array;
};


#endif
