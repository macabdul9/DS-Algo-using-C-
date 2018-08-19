#include <iostream>
#include <algorithm>
using namespace std;

void mergerSort(int arr[], int start, int end);

void merge(int arr[], int start, int mid, int end);

int main(int argc, char const *argv[])
{
	int arr[] {4,3,-34,24,56,10};
	int size = *(&arr + 1) - arr;
	mergerSort(arr, 0, size - 1);
	for(int i = 0; i < size ; i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}
void mergerSort(int arr[], int start, int end){
	if (start < end)
	{
		int mid =  (start + end)/2;
		mergerSort(arr, start, mid);
		mergerSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
	else{
		return;
	}

}
void merge(int arr[], int start, int mid, int end){
	/* 
		+1 becuase suppose you have a subarray of three elements then 
		left subarray will have two and right subarray will have only one elements. 
	*/
	int size_left = mid - start + 1;
	int size_right = end - mid;

	int left_array[size_left];
	int right_array[size_right];

	for(int i = 0; i < size_left; i++)
		left_array[i] = arr[start + i];
	for(int j = 0; j < size_right; j++)
		right_array[j] = arr[mid + 1 + j]; 

	int i = 0;
	int j = 0;
	int k = start;
	while (i < size_left and j < size_right){
		if (left_array[i] <= right_array[j])
		{	
			arr[k] = left_array[i];
			i++;
			k++;
			/* code */
		}else{
			arr[k] = right_array[j];
			j++;
			k++;
		}
	}
	//flush the remaining elements from both array
	while(i < size_left){
		arr[k] = left_array[i];
		i++;
		k++;
	}
	while(j < size_right){
		arr[k] = right_array[j];
		j++;
		k++;
	}
}