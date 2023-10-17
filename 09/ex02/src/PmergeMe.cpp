#include "../include/PmergeMe.hpp"

template <typename T>
void	print(T &container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void merge_sort_vector(T &v)
{
	if (v.size() <= 1)
		return;

	T left, right;
	int middle = v.size() / 2;

	for (int i = 0; i < middle; ++i)
		left.push_back(v[i]);

	for (int i = middle; i < (int)v.size(); ++i)
		right.push_back(v[i]);

	merge_sort_vector(left);
	merge_sort_vector(right);

	std::merge(left.begin(), left.end(), right.begin(), right.end(), v.begin());
}

template <typename T>
void merge_sort_list(T &l)
{
	if (l.size() <= 1)
		return;

	T left, right;
	int middle = l.size() / 2;

	typename T::iterator it = l.begin();
	for (int i = 0; i < middle; ++i)
		left.push_back(*it++);

	for (int i = middle; i < (int)l.size(); ++i)
		right.push_back(*it++);

	merge_sort_list(left);
	merge_sort_list(right);

	left.merge(right);
	l = left;
}


void PmergeMe(int argc, char **argv)
{
	double	v_duration;
	double	l_duration;
	int		num;
	std::vector<int> v;
	std::list<int> l;

	std::cout << std::fixed << std::setprecision(9);

	for (int i = 1; i < argc; ++i)
	{
		if (std::stoi(argv[i]) < 0)
		{
			std::cout << "Error: negative numbers are not allowed" << std::endl;
			return;
		}
	}

	std::cout << "Before:\t";
	for (int i = 1; i < argc; ++i)
	{
		num = std::stoi(argv[i]);

		v.push_back(num);
		l.push_back(num);
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::clock_t start_v = std::clock();
	merge_sort_vector(v);
	v_duration = (std::clock() - start_v) / (double)(CLOCKS_PER_SEC * 1000);


	std::clock_t start_l = std::clock();
	merge_sort_list(l);
	l_duration = (std::clock() - start_l) / (double)(CLOCKS_PER_SEC * 1000);

	std::cout << "After:\t";
	print(l);

	std::cout
		<< "Time to process a range of "
		<< argc - 1
		<< " elements with std::vector :\t"
		<< v_duration
		<< " μs"
		<< std::endl;

	std::cout
		<< "Time to process a range of "
		<< argc - 1
		<< " elements with std::list :\t\t"
		<< l_duration
		<< " μs"
		<< std::endl;
}
