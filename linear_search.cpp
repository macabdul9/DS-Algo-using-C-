#include <iostream>
using std::cout;
using std::cin;
int linearSearch(int arr[], int size, int find, int index);

int main(){
	int arr[] = { 4,2,9,15,34,67,12,89,10,0 };
	int size = sizeof(arr)/sizeof(*arr);
	cout << linearSearch(arr, size, 13, 0); 
	return 0;
	
}
int linearSearch(int arr[], int size, int find, int index){
	if ( index >= size ){
		return -1;
	}
	if(arr[index] == find){
		return index;
	}
	linearSearch(arr, size, find, index+1 );
}
	
