
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include	<vector>
//#include	<cstddef>
#include	<string>

template<typename T, template<class _Tp, class _Allocator> class Arr>
class PmergeMe{
private:
	typedef typename	Arr<T, std::allocator<T> >::iterator				t_arr_iter; 
	typedef	typename	std::pair<T, T>										t_pair;
	typedef class		Arr<t_pair, std::allocator<t_pair> >				t_contain_pair;
	typedef	typename	t_contain_pair::iterator							t_contain_pair_iter;

	Arr<T, std::allocator<T> >	_arr;
	clock_t						_sort_time;

	size_t	strToSizet( std::string const &str ) const;

	void	mergeInsertionSort();
	void	makePair( t_contain_pair &pair_arr );
	void	movePairFristToArr( t_contain_pair &pair_arr );

	void	mergeSort( t_contain_pair &arr, t_contain_pair& merge, size_t start, size_t end );	
	void	mergeArr( t_contain_pair &arr, t_contain_pair &merge, size_t start, size_t end );
	void	pasteArrNum( t_contain_pair &from_arr, t_contain_pair &to_arr, size_t *f, size_t *t );

	void	binaryInsertionSort( t_contain_pair &arr );
	int		binarySearch( size_t target, size_t low );

public:
	PmergeMe( void );
	PmergeMe( PmergeMe const &origin );
	~PmergeMe( void );

	PmergeMe	&operator=( PmergeMe const &origin );

	int	insertUnsortedNumbers( char *argv[] );
	int	insertUnsortedNumbers( Arr<T, std::allocator<T> > &arr );

	void	sortArray();
	void	clear();
	void	showArray();
	double	getSortTime() const;
};

# endif
