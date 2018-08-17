#include <iostream>
#include <algorithm>
using namespace std;
bool binarySearchRecursive(int[], int start, int end, int find);
int main(){
	int arr[] = { 23, 44, 67, 43, 12, 69, 41, 27, 90, 123 };
	int size = sizeof(arr)/sizeof(*arr);
	sort(arr, arr + size);
	// 1- true 
	// 0-false
	cout <<  binarySearchRecursive(arr, 0, size-1, 1) << "\n";	
	return 0;
}
bool binarySearchRecursive(int arr[], int start, int end, int find){
	int mid = ( start + end ) / 2;
	if (start  > end){
		return false;
	}
	if(arr[mid] == find){
		return true;
	}
	else if(find > arr[mid]){
		binarySearchRecursive(arr, mid+1, end, find);
	}
	else{
		binarySearchRecursive(arr, start, mid-1, find);
	}
}
