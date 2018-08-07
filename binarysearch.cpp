#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearchRecursive(int[], int mid, int left, int right, int target);
int main(){
	int arr[] = { 23, 44, 67, 43, 12, 69, 41, 27, 90, 123 };
	int size = sizeof(arr)/sizeof(*arr);
	
	sort(arr, arr+10);
	
	//for(int index = 0; index < sizeof(arr)/sizeof(*arr); index++){
	//	
	//	cout << arr[index] << " " ;
	//}
	
	cout <<  binarySearchRecursive(arr, size/2, 0,size-1, 12) << "\n";	
	return 0;
}

bool binarySearchRecursive(int arr[], int mid, int left, int right, int target){
	
	mid = ( left + right ) / 2;
	if (left  > right){
		return false;
	}
	if(arr[mid] == target){
		return true;
	}
	else if(target > arr[mid]){
		binarySearchRecursive(arr, mid, mid+1,right, target);
	}
	else{
		binarySearchRecursive(arr, mid, left, mid-1, target);
	}

}
	
