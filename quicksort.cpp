#include <iostream>
#include<algorithm>
using namespace std;
void quicksort(int arr[], int start, int end);
int main(int argc, char const *argv[])
{
	int arr[] {43, 54, 6, 46, 49, 20, -3, 0, -10, 16};
	int size = sizeof(arr)/sizeof(*arr);
	quicksort(arr, 0, size - 1);
	for(int& e : arr){
		cout << e << " ";
	}
	cout <<"\n";
	return 0;
}

void quicksort(int arr[], int start, int end){

	// break point
	if (start >= end)
	{
		return;
	}
	//pivot could be any element of array
	int pivot = arr[end];
	int i = start - 1;
	for (int j = start ; j < end; j++){
		if(arr[j] <= pivot ){
			i = i + 1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[end]);
	quicksort(arr, start, i);
	quicksort(arr, i + 2, end);
}
