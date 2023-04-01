
#include	"PmergeMe.hpp"
#include	"PmergeMe.cpp"

#include	<iostream>
#include	<vector>
#include	<deque>


#include <unistd.h> 

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		PmergeMe<int, std::vector >	vector_me;
		PmergeMe<int, std::deque >  deque_me;

		if (vector_me.insertUnsortedNumbers(argv) == 1 \
			&& deque_me.insertUnsortedNumbers(argv) == 1)
		{
			std::cout << "Before: ";
			vector_me.showArray();
			vector_me.sortArray();
			deque_me.sortArray();
			std::cout << "After:  ";
			vector_me.showArray();

			std::cout << "Time to process a range of 3000 elements with std::vector : "
						<< 1000.0 * vector_me.getSortTime() / CLOCKS_PER_SEC << " ms" << std::endl;
			std::cout << "Time to process a range of 3000 elements with std::deque : "
						<< 1000.0 * deque_me.getSortTime() / CLOCKS_PER_SEC << " ms" << std::endl;
		}
	}
	return 0;
}
