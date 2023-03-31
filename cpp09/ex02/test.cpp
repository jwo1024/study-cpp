
//#include	"PmergeMe.hpp"

#include	<vector>
#include	<iostream>


template<typename T>
void	mergeSort(T &arr, T& merge,  int start, int end);
template<typename T>
void	merge_arr(T &arr, T &merge, int start, int end);


template<typename T>
void	mergeSort(T &arr, T& merge,  int start, int end) // pair로 다루는게 편하려나. 
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
void	paste_arr_num(T &from_arr, T &to_arr, int *f, int *t) // pair.
{
//	if (from_arr && to_arr)
	{
		to_arr[*t].first = from_arr[*f].first;
		to_arr[*t].second = from_arr[*f].second;
		(*f)++;
		(*t)++;
	}
	/*
	std::cout << "j : " << j << " k " << k << std::endl;
	merge[j].first = arr[k].first;
	merge[j].second = arr[k].second;
	merge[j + 1].first = arr[k + 1].first;
	merge[j + 1].second = arr[k + 1].second;

	k += 2;
	j += 2;*/

}

template<typename T>
void	merge_arr(T &arr, T &merge, int start, int end)
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






///////////////




void	swapIntPair(std::vector<std::pair<int, int> >::iterator &iter)
{
	int	tmp;

	tmp = (*iter).first;
	(*iter).first = (*iter).second;
	(*iter).second = tmp;
}




template<typename T > // 작은것 부터 정렬되게끔 해두었으니, start 뒤의 숫자 중에서 idx를 찾아야한다.
void	binarySearchInsert(T &arr, int target, int low) // target = 9 low = 2
{
    int high = arr.size() - 1;
    int mid;

    while(low <= high)
	{
        mid = (low + high) / 2;

        if (arr[mid] == target)
			;
		else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
	

	arr.push_back(0);
	int	tail = arr.size() - 1;

	std::cout << "low " << low << " tail " << tail << std::endl;

	while (low < tail)
	{
		arr[tail] = arr[tail - 1];
		tail--;
	}
	arr[tail] = target;
	return ;


}



///////


// only randomaccess iterator
//template<typename T>
void	mergeInsertionSort(std::vector<int> &arr)
{
	std::vector<std::pair<int, int> > pair_vec;
	//	pair_vec.capacity( arr.size() / 2); + if odd number 
	bool odd_numbers = false;
	int	odd_num; // 깍두기
	if (arr.size() % 2)
	{
		odd_num = arr.back(); 
		odd_numbers = true;
	}

// 1. make pair
	for (int idx1 = 0, idx2 = arr.size() / 2; idx1 != arr.size() / 2;)
	{
		pair_vec.push_back(std::make_pair(arr[idx1], arr[idx2]));
		std::cout << arr[idx1] << " " << arr[idx2] << std::endl;
		idx1++;
		idx2++;
	}

// 2. pair 대소 구분 정렬
	for (std::vector<std::pair<int, int> >::iterator iter = pair_vec.begin(); iter != pair_vec.end(); iter++)
	{
		std::cout << "iter pair_vec : " << (*iter).first << std::endl;

		if ((*iter).first > (*iter).second) // iter 1에 작은 수 배열
			swapIntPair(iter);
	}

//	3. merge sort 
	std::vector<std::pair<int, int> > merge(pair_vec.size());
	mergeSort(pair_vec, merge, 0, pair_vec.size() - 1);

	std::cout << "after merge pair ==" << std::endl;
	for (std::vector<std::pair<int, int> >::iterator iter = pair_vec.begin(); iter != pair_vec.end(); iter++)
		std::cout << "iter pair first : " << (*iter).first << " second " << (*iter).second << std::endl;


// 4. 옮겨 저장
	arr.clear();
	for (std::vector<std::pair<int, int> >::iterator iter = pair_vec.begin(); iter != pair_vec.end(); iter++)
		arr.push_back((*iter).first);
	
	std::cout << "result arr ==" << std::endl;
	for (std::vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
		std::cout << " " << *iter;
	std::cout << std::endl;



// 5.  binary search && insertion sort
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


// 	결과출력
	std::cout << "result arr ==" << std::endl;
	for (std::vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
		std::cout << " " << *iter;
	std::cout << std::endl;

}


// 중복 숫자 에러 처리
// 클래스로 옮기기
// main 인자 받도록 수정
// 파싱 하기
// 숫자 정렬 출력
// 정렬 걸리는 시간초 출력 

int	main( void )
{
	int	arr[] = {-3, 7, 5, 0, 33, 4 ,2, -9, 8, 11, 10, 34 , -50, 32, 24, 1, 12};
	std::vector<int>	vector_arr(arr, &arr[17]);

	for (std::vector<int>::iterator iter = vector_arr.begin(); iter != vector_arr.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	mergeInsertionSort(vector_arr);

//	for (std::vector<int>::iterator iter = vector_arr.begin(); iter != vector_arr.end(); iter++)
//		std::cout << *iter << " ";
//	std::cout << std::endl;

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

