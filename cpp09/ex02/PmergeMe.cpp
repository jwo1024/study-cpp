
#include	"PmergeMe.hpp"

template<typename T>
PmergeMe<T>::PmergeMe( void )
{
	;
}

template<typename T>
PmergeMe<T>::PmergeMe( PmergeMe const &origin )
{
	;
}

template<typename T>
PmergeMe<T>::~PmergeMe( void )
{
	;
}

//PmergeMe	&operator=( PmergeMe const &origin );

template<typename T>
int	PmergeMe<T>::insertUnsortedNumbers( char *argv[] )
{
	while (argv)
	{
		if (1) // is_num
			;
		argv++;
	}
}

template<typename T > // int type 이라는 걸 가정 ?
int	PmergeMe<T>::insertUnsortedNumbers( T &arr )
{
	this->_array = arr;
}

template<typename T>
int	PmergeMe<T>::insertUnsortedNumbers( int *arr )
{
	;
}

// ===============================




template<typename T>
void	PmergeMe<T>::showArray()
{
	for (T::iterator iter = this->_arr.begin(); iter != this->_arr.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

template<typename T>
void	PmergeMe<T>::sortArray() //
{

	std::vector<std::pair<int, int> > pair_vec; // ?

	bool odd_numbers = false;
	int	odd_num; // 깍두기

	if (this_arr.size() % 2)
	{
		odd_num = arr.back(); 
		odd_numbers = true;
	}

// makePair
	makePair(pair_vec);

// merge sort
	std::vector<std::pair<int, int> > merge(pair_vec.size());
	mergeSort(pair_vec, merge, 0, pair_vec.size() - 1);

// 옮겨 저장
	arr.clear();
	for (std::vector<std::pair<int, int> >::iterator iter = pair_vec.begin(); iter != pair_vec.end(); iter++)
		arr.push_back((*iter).first);

// binary insertion sort
	{
		int	idx = pair_vec.size() - 1; // tail to first 
	
		while (idx >= 0)
		{
			binarySearchInsert(arr, pair_vec[idx].second, idx);
			idx--;
		}
		if (odd_numbers)
			binarySearchInsert(arr, odd_num, idx);
	}

}


template <typename T >
template< typename T2 >
void	PmergeMe<T>::makePair( T2 &pair_vec )
{
	//	pair_vec.capacity( arr.size() / 2); + if odd number 
	
	int	idx1 = 0;
	int	idx2 = this->_arr.size() / 2;
	while (idx1 != this->_arr.size() / 2)
	{
		if (this->_arr[idx1] < this->_arr[idx2])
			pair_vec.push_back(std::make_pair(this->_arr[idx1], this->_arr[idx2]));
		else if (this->_arr[idx1] > this->_arr[idx2])
			pair_vec.push_back(std::make_pair(this->_arr[idx1], this->_arr[idx2]));
		else
			std::cout << "same num error neeeed to " << std::endl;
		std::cout << this->_arr[idx1] << " " << this->_arr[idx2] << std::endl;
		idx1++;
		idx2++;
	}	
}




/* ======= Merge Sort ======= */

template<typename T> // T2? 
template< typename T2 > /////// ?
void	PmergeMe<T>::mergeSort(T &arr, T& merge,  int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(arr, merge, start, mid);
		mergeSort(arr, merge, mid + 1, end);
		merge_arr(arr, merge, start, end);
	}
}

template<typename T>
template< typename T2 >
void	PmergeMe<T>::merge_arr(T &arr, T &merge, int start, int end)
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
			paste_arr_num(arr, merge, &fro, &mer);
		else
			paste_arr_num(arr, merge, &bac, &mer);
	}
	while (fro <= mid)
		paste_arr_num(arr, merge, &fro, &mer);
	while (bac <= end)
		paste_arr_num(arr, merge, &bac, &mer);
	
	fro = 0;
	while (fro < mer)
		paste_arr_num(merge, arr, &fro, &start);
}

template<typename T>
template< typename T2 >
void	PmergeMe<T>::paste_arr_num(T &from_arr, T &to_arr, int *f, int *t) // pair.
{
	to_arr[*t].first = from_arr[*f].first;
	to_arr[*t].second = from_arr[*f].second;
	(*f)++;
	(*t)++;
}





