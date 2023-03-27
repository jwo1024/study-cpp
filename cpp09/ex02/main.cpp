
//#include	"PmergeMe.hpp"

#include	<vector>
#include	<iostream>

template<typename T>
void	insertionSort(T &arr)
{
	int i, j;
	for(i = 1; i < arr.size(); i++)
	{
   		int key = arr[i];
	    for(j=i-1; j>=0 && arr[j]>key; j--){
    		arr[j+1] = arr[j];
 		}
    	arr[j+1] = key;
  	}
}


int	main( void )
{
	int	arr[] = {3, 2 ,4, 5 ,7, 8};
	std::vector<int>	vector_arr(arr, &arr[6]);

	for (std::vector<int>::iterator iter = vector_arr.begin(); iter != vector_arr.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	insertionSort(vector_arr);

	for (std::vector<int>::iterator iter = vector_arr.begin(); iter != vector_arr.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	
	return 0;
}



/*
int	main(int argc, char *argv[])
{
	if (argc >= 2 && argv)
	{
		;
	}
	return 0;
}
*/

