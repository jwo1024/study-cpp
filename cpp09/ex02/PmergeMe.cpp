
#include	"PmergeMe.hpp"

#include	<iostream>
//#include	<iterator> //
#include <chrono>



template<typename T, template<class _Tp, class _Allocator> class Arr>
PmergeMe<T, Arr>::PmergeMe( void )
{
	;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
PmergeMe<T, Arr>::PmergeMe( PmergeMe const &origin )
{
	*this = origin;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
PmergeMe<T, Arr>::~PmergeMe( void )
{
	;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
PmergeMe<T, Arr>	&PmergeMe<T, Arr>::operator=( PmergeMe<T, Arr> const &origin )
{
	this->_arr = origin._arr;
	this->_sort_time = origin._sort_time;
}


/* ======= Utils ======= */

template<typename T, template<class _Tp, class _Allocator> class Arr>
int	PmergeMe<T, Arr>::insertUnsortedNumbers( char *argv[] )
{
	while (argv)
	{
		if (1) // is_num
			;
		argv++;
	}
	return 1;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
int	PmergeMe<T, Arr>::insertUnsortedNumbers( Arr<T, std::allocator<T> > &arr )
{
	this->_arr = arr;
	return 1;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
int	PmergeMe<T, Arr>::insertUnsortedNumbers( int *arr )
{
	(void)arr;
	return 1;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::showArray()
{
	for (t_arr_iter iter = this->_arr.begin(); iter != this->_arr.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
double	PmergeMe<T, Arr>::getSortTime()
{
	return this->_sort_time;
}


/* ======= Sort ======= */

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::sortArray() //
{
//	double	start_time, end_time;
	t_contain_pair	pair_arr;
	bool			arr_odd_num;
	int				odd_num;

//	start_time = (double)clock();
//	std::chrono::steady_clock::time_point start_time, end_time;
	std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
	
	if (this->_arr.size() % 2)
	{
		odd_num = this->_arr.back(); 
		arr_odd_num = true;
	}
	else
		arr_odd_num = false;

	pair_arr.reserve(this->_arr.size() / 2);
	makePair(pair_arr);

	{
		t_contain_pair	merge;

		merge.reserve(this->_arr.size() / 2);
		mergeSort(pair_arr, merge, 0, pair_arr.size() - 1);
	}

	movePairFristToArr( pair_arr);
	binaryInsertionSort(pair_arr);

	if (arr_odd_num)
	{
		int	pos;
		pos = binarySearch(odd_num, this->_arr.size() - 1);
		insertArr(odd_num, pos);
	}

//	end_time = (double)clock();
	std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();

//	std::chrono::microseconds micro = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	std::cout << "sorting time : " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << std::endl;

}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::makePair( t_contain_pair &pair_arr )
{
	//	pair_arr.capacity( arr.size() / 2); + if odd number 	
	int	idx1 = 0;
	int	idx2 = this->_arr.size() / 2;

	while (idx1 != this->_arr.size() / 2)
	{
		if (this->_arr[idx1] < this->_arr[idx2])
			pair_arr.push_back(std::make_pair(this->_arr[idx1], this->_arr[idx2]));
		else if (this->_arr[idx1] > this->_arr[idx2])
			pair_arr.push_back(std::make_pair(this->_arr[idx2], this->_arr[idx1]));
		else
			std::cout << "same num error neeeed to " << std::endl;
		idx1++;
		idx2++;
	}	
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::movePairFristToArr( t_contain_pair &pair_arr )
{
	this->_arr.clear();
	for (t_contain_pair_iter iter = pair_arr.begin(); iter != pair_arr.end(); iter++)
		this->_arr.push_back((*iter).first);

}





/* ======= Binary Insertion Sort ======= */

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::binaryInsertionSort(t_contain_pair &pair_arr)
{
	int	idx = pair_arr.size() - 1; // tail to first 
	int	pos;

	while (idx >= 0)
	{
		pos = binarySearch(pair_arr[idx].second, idx);
		insertArr(pair_arr[idx].second, pos);
		idx--;
	}
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
int	PmergeMe<T, Arr>::binarySearch(int target, int low)
{
    int high = this->_arr.size() - 1;
    int mid;

	while(low <= high)
	{
		mid = (low + high) / 2;

		if (this->_arr[mid] == target)
			;
		else if (this->_arr[mid] > target)
			high = mid - 1;
        else
			low = mid + 1;
	}
	return low;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::insertArr(int target, int pos) // int? pos size_t? 
{
	int	tail;

	this->_arr.push_back(0);
	tail = this->_arr.size() - 1;
	while (pos < tail)
	{
		this->_arr[tail] = this->_arr[tail - 1];
		tail--;
	}
	this->_arr[tail] = target;
	return ;
}



/* ======= Merge Sort ======= */

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::mergeSort(t_contain_pair &arr, t_contain_pair& merge, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(arr, merge, start, mid);
		mergeSort(arr, merge, mid + 1, end);
		mergeArr(arr, merge, start, end);
	}
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::mergeArr(t_contain_pair &arr, t_contain_pair &merge, int start, int end)
{
	int	mid;
	int	fro;
	int	bac;
	int	mer;

	mid = (start + end) / 2;
	fro = start;
	bac = mid + 1;
	mer = 0;
	while (fro <= mid && bac <= end)
	{
		if (arr[fro].first <= arr[bac].first)
			pasteArrNum(arr, merge, &fro, &mer);
		else
			pasteArrNum(arr, merge, &bac, &mer);
	}
	while (fro <= mid)
		pasteArrNum(arr, merge, &fro, &mer);
	while (bac <= end)
		pasteArrNum(arr, merge, &bac, &mer);
	
	fro = 0;
	while (fro < mer)
		pasteArrNum(merge, arr, &fro, &start);
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::pasteArrNum(t_contain_pair &from_arr, t_contain_pair &to_arr, int *f, int *t) // pair.
{
	to_arr[*t].first = from_arr[*f].first;
	to_arr[*t].second = from_arr[*f].second;
	(*f)++;
	(*t)++;
}



//template class PmergeMe<std::Vector<int> >;
//template class PmergeMe<std::Deque<int> >;


