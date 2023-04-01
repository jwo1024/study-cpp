
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include	<vector>

// https://learn.microsoft.com/ko-kr/cpp/cpp/templates-cpp?view=msvc-170

template<typename T, template<class _Tp, class _Allocator> class Arr>
class PmergeMe{
private:
	typedef typename	Arr<T, std::allocator<T> >::iterator			t_arr_iter; // ? doesnt work 
	typedef	typename	std::pair<int, int>								t_pair_int;
	typedef class		Arr<t_pair_int, std::allocator<t_pair_int> >	t_contain_pair;
	typedef	typename	t_contain_pair::iterator 						t_contain_pair_iter;

	Arr<T, std::allocator<T> >	_arr;
	std::clock_t				_sort_time;

	int		strToInt( std::string const &str ) const;

	void	mergeInsertionSort();
	void	makePair( t_contain_pair &pair_arr );
	void	movePairFristToArr( t_contain_pair &pair_arr );

	void	mergeSort(t_contain_pair &arr, t_contain_pair& merge,  int start, int end);	
	void	mergeArr(t_contain_pair &arr, t_contain_pair &merge, int start, int end);
	void	pasteArrNum(t_contain_pair &from_arr, t_contain_pair &to_arr, int *f, int *t);

	void	binaryInsertionSort(t_contain_pair &arr);
	int		binarySearch(int target, int low);
	void	insertArr(int target, int pos);

public:
	PmergeMe( void );
	PmergeMe( PmergeMe const &origin );
	~PmergeMe( void );

	PmergeMe	&operator=( PmergeMe const &origin );

	int	insertUnsortedNumbers( char *argv[] );
	int	insertUnsortedNumbers( Arr<T, std::allocator<T> > &arr );

	void	showArray();// const;
	void	sortArray();
	double	getSortTime();// const; // double ? 
	void	clear();

};



# endif
