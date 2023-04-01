
#include	"PmergeMe.hpp"

#include	<iostream>
#include	<sstream>
#include	<iomanip> // std::setprecision()


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
	
	for (int idx = 1; argv[idx] ; idx++)
	{
		std::string	str = argv[idx];
		int num = strToInt( argv[idx]);
		if (str.find_first_not_of("0123456789") != std::string::npos)
		{
			this->_arr.clear();
			std::cout << "Error" << std::endl;
			return -1;
		}
		else
			this->_arr.push_back(num);
	}
	return 1;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
int	PmergeMe<T, Arr>::strToInt( std::string const &str ) const
{
	int					value;
	std::stringstream	stream;

	stream.str(str);
	stream >> value;
	return value;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
int	PmergeMe<T, Arr>::insertUnsortedNumbers( Arr<T, std::allocator<T> > &arr )
{
	this->_arr = arr;
	return 1;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::showArray()
{
	int	cnt = 0;
	for (t_arr_iter iter = this->_arr.begin(); iter != this->_arr.end(); iter++)
	{
		cnt += 1;
		if (cnt > 7)
		{
			std::cout << " [...]";
			break ;
		}
		std::cout << " " << *iter ;
	}
	std::cout << std::endl;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
double	PmergeMe<T, Arr>::getSortTime()
{
	return this->_sort_time;
}


/* ======= Sort ======= */

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::PmergeMe<T, Arr>::mergeInsertionSort()
{
	t_contain_pair	pair_arr(this->_arr.size() / 2);
	t_contain_pair	merge(this->_arr.size() / 2);
	bool			arr_odd_num;
	int				odd_num;

	if (this->_arr.size() % 2)
	{
		odd_num = this->_arr.back(); 
		arr_odd_num = true;
	}
	else
		arr_odd_num = false;
	makePair(pair_arr);

	mergeSort(pair_arr, merge, 0, pair_arr.size() - 1);

	movePairFristToArr(pair_arr);

	binaryInsertionSort(pair_arr);

	pair_arr.clear();
	if (arr_odd_num)
	{
		int	pos;
		pos = binarySearch(odd_num, 0);
		insertArr(odd_num, pos);
	//	this->_arr.insert(this->_arr.begin() + pos, odd_num);
	}
}


template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::sortArray() //
{
	if (this->_arr.empty())
		return ;
	std::clock_t c_start, c_end;

	c_start = clock();
	if (this->_arr.size() > 1)
		mergeInsertionSort();
    c_end = clock();
	this->_sort_time = c_end - c_start;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::makePair( t_contain_pair &pair_arr )
{
	int	idx1 = 0;
	int	idx2 = this->_arr.size() / 2;

	while (idx1 != this->_arr.size() / 2)
	{
		if (this->_arr[idx1] < this->_arr[idx2])
		{
			pair_arr[idx1].first = this->_arr[idx1];
			pair_arr[idx1].second = this->_arr[idx2];
		}
		else
		{
			pair_arr[idx1].first = this->_arr[idx2];
			pair_arr[idx1].second = this->_arr[idx1];
		}
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
	//	this->_arr.insert(this->_arr.begin() + pos, pair_arr[idx].second);
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
			break ;
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


