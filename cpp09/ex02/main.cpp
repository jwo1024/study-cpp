
#include	"PmergeMe.hpp"
#include	"PmergeMe.cpp"

#include	<iostream>
#include	<vector>
#include	<deque>

int	main(int argc, char *argv[])
{
	if (argc && argv)
		;
	int	arr[] = {-3, 7, 5, 0, 33, 4 ,2, -9, 8, 11, 10, 34 , -50, 32, 24, 1, 12};
	std::vector<int>	vector_arr(arr, &arr[16]);

	for (std::vector<int>::iterator iter = vector_arr.begin(); iter != vector_arr.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

//	mergeInsertionSort(vector_arr);


	PmergeMe<int, std::vector >  merge_me;

	merge_me.insertUnsortedNumbers(vector_arr);
	merge_me.showArray();
	merge_me.sortArray();
	merge_me.showArray();

	return 0;
}
