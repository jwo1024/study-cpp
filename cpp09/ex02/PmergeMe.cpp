
#include	"PmergeMe.hpp"

#include	<iostream>
#include	<sstream>
#include	<string>

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
	
	for (size_t idx = 1; argv[idx] ; idx++)
	{
		std::string	str = argv[idx];
		size_t num = strToSizet( argv[idx]);
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
size_t	PmergeMe<T, Arr>::strToSizet( std::string const &str ) const
{
	size_t				value;
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
	std::string			str;
	std::stringstream	ss_num;
	for (t_arr_iter iter = this->_arr.begin(); iter != this->_arr.end(); iter++)
	{
		str.append(" ");
		ss_num << *iter;
		str.append(ss_num.str());
		ss_num.str("");
		if (str.size() > 20)
		{
			str.append(" [...]");
			break ;
		}
	}
	std::cout << str << std::endl;

}

template<typename T, template<class _Tp, class _Allocator> class Arr>
double	PmergeMe<T, Arr>::getSortTime() const
{
	return this->_sort_time;
}


/* ======= Sort ======= */

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::mergeInsertionSort()
{
	t_contain_pair	pair_arr(this->_arr.size() / 2);
	t_contain_pair	merge(this->_arr.size() / 2);
	bool			arr_odd_num;
	size_t			odd_num;

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
		size_t	pos;
		pos = binarySearch(odd_num, 0);
		this->_arr.insert(this->_arr.begin() + pos, odd_num);
	}
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::sortArray()
{
	if (this->_arr.empty())
		return ;
	clock_t	c_start, c_end;

	c_start = clock();
	if (this->_arr.size() > 1)
		mergeInsertionSort();
    c_end = clock();
	this->_sort_time = c_end - c_start;
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::makePair( t_contain_pair &pair_arr )
{
	size_t	idx1 = 0;
	size_t	idx2 = this->_arr.size() / 2;

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
	size_t	idx = pair_arr.size() - 1;
	size_t	pos;

	while (idx >= 0)
	{
		pos = binarySearch(pair_arr[idx].second, idx);
		this->_arr.insert(this->_arr.begin() + pos, pair_arr[idx].second);
		if (idx == 0)
			break ;
		idx--;
	}
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
int	PmergeMe<T, Arr>::binarySearch(size_t target, size_t low)
{
    size_t high = this->_arr.size() - 1;
    size_t mid;

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


/* ======= Merge Sort ======= */

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::mergeSort(t_contain_pair &arr, t_contain_pair& merge, size_t start, size_t end)
{
	size_t	mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(arr, merge, start, mid);
		mergeSort(arr, merge, mid + 1, end);
		mergeArr(arr, merge, start, end);
	}
}

template<typename T, template<class _Tp, class _Allocator> class Arr>
void	PmergeMe<T, Arr>::mergeArr(t_contain_pair &arr, t_contain_pair &merge, size_t start, size_t end)
{
	size_t	mid, fro, bac, mer;

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
void	PmergeMe<T, Arr>::pasteArrNum(t_contain_pair &from_arr, t_contain_pair &to_arr, size_t *f, size_t *t) // pair.
{
	to_arr[*t].first = from_arr[*f].first;
	to_arr[*t].second = from_arr[*f].second;
	(*f)++;
	(*t)++;
}
