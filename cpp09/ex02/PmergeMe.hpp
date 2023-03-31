
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include	<vector>

template<typename T>
class PmergeMe{
private:
	typedef typename T::iterator iterator; // ? doesnt work 

	T		_array;
	double	_sort_time;

	void mergeInsertionSort();
	
	binarySearchInsert();
	mergeSort();
	mergeArr();
	mergePasteArr();
	swapIntPair();

public:
	PmergeMe( void );
	PmergeMe( PmergeMe const &origin );
	~PmergeMe( void );

	PmergeMe	&operator=( PmergeMe const &origin );

	int	insertUnsortedNumbers( char *argv[] );
	int	insertUnsortedNumbers( T &arr );
	int	insertUnsortedNumbers( int *arr	);

	void	showArray();
	void	sortArray();
	void	getSortTime(); // double ? 

	;//clearArray();

};


# endif




