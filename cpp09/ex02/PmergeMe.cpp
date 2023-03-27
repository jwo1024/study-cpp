
#include	"PmergeMe.hpp"

/* ====== ; ====== */

/*
template<typename T>
T	&PmergeMe::mergeSort( T &arr, iterator start, iterator end)
{
	typedef typename	T::iterator	iter;
	iter		mid;

	if ( start + 1 < end )
	{
		// set과 같은 bidirectionalIterator의 경우 iterator 의 + / 연산이 불가능하다.
		mid = (start + end) / 2; 

		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		mergeArr(arr, start, mid, end);
	}
	return arr;
}

template<typename T>
T	&PmergeMe::mergeArr( T &arr, iter start, iter mid, iter end )
{
	iter	idx1 = 0, idx2 = mid + 1;

	while (idx1 < mid && idx2 < end)
	{
		;
	}


}
*/



template<typename T>
template<typename T::iterator iter>
void PmergeMe::insertionSort( iter start, iter end,  std::random_access_iterator_tag )
{
//	typename std::iterator_traits<iterator>::value_type	val  = start;

	int	len;

	typename iter s = start++; // ?
	typename iter e = end; //

	for ( ; s != e ; s++)
	{
		key = s;
	
		typename iter j = key - 1;
	
		for ( ; j != start && *key < *j ; j--)
			j[1] = j[0];
		
		*j = *key;

	}

}

