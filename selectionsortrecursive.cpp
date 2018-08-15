//sorting by recursion
#include <iostream>
using std::cout;
using std::cin;
void sort(int arr[], int start, int end);
int main(){
	int arr[5];
	for (int i = 0; i < 5; i++){
		cin >> arr[i];
	}
	sort(arr, 0, 5);
	for (int i = 0;  i < 5; i++){
		cout << arr[i] << " ";
	}

}
void sort(int arr[], int start_index, int end_index){
	if(start_index < end_index){
		int temp;
		if(arr[start_index] > arr[end_index]){
			temp = arr[start_index];
			arr[start_index] = arr[end_index];
			arr[end_index] = temp;
		}
		sort(arr, start_index, end_index-1);
		sort (arr, start_index + 1, end_index);
	       	return ;	
	}else{
		return; 
	}
	
}


