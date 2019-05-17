#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
void insertionSortRecursive(int arr[], int pivot, int size);
int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {3,-90,0,24,46};
	int size = sizeof(arr)/sizeof(*arr);
	insertionSortRecursive(arr, 1, size);
	for(int& element:arr){
		cout << element << "\n";
	}
	return 0;
}
void insertionSortRecursive(int arr[], int pivot, int size){
	if (pivot < size){
		int i = pivot - 1;
		int key = arr[pivot];
		while ( i > -1 && arr[i] < key){
			arr[i+1] = arr[i];
			i -= 1;
		}
		arr[i+1] = key;
		insertionSortRecursive(arr, pivot+1, size);
	}
	else{
		return;
	}	
}