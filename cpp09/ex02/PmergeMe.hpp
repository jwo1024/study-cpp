
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include	<vector>

template<typename T>
class PmergeMe{
private:
	typedef typename T::iterator iterator; // ? doesnt work 

	T	result_arr;
	T	tmp_arr;

	T	&mergeSort( T<int> &arr );

	template<typename iterator iter>
	void	insertionSort(iterator start, iterator end,  std::random_access_iterator_tag );

public:
	PmergeMe( void );
	PmergeMe( PmergeMe const &origin );
	~PmergeMe( void );

	PmergeMe	&operator=( PmergeMe const &origin );


};



# endif

