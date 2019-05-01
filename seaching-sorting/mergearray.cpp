#include <iostream>
#include <algorithm>
using namespace std;

void mergearray(int arr_1[], int size_1, int arr_2[], int size_2, int arr[]);
int main(int argc, char const *argv[])
{
	int arr_1[] = {-4,5,-20};
	int arr_2[] = {0,12,2,9,4,92};

	//size of the both array that we have to merge into signle sorted array
	int size_1 = sizeof(arr_1)/sizeof(*arr_1);
	int size_2 = sizeof(arr_2)/sizeof(*arr_2);

	// sorting the array
	sort(arr_1, arr_1 + size_1);	
	sort(arr_2, arr_2 + size_2);

	int arr[size_1 + size_2];

	mergearray(arr_1,size_1, arr_2, size_2, arr);

	for (int& e:arr){
		cout << e << " ";
	}
	cout << "\n";																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																					
	return 0;
}
void mergearray(int arr_1[], int size_1, int arr_2[], int size_2, int arr[]){	
	
	int i = 0;
	int j = 0;
	//copying the array into anther by comparing
	while(i < size_1 and j < size_2){
		if (arr_1[i] <= arr_2[j])
		{
			arr[i+j] = arr_1[i];
			i++;
		}
		else{
			arr[i+j] = arr_2[j];
			j++;
		}
	}
	// flush the both array
	while( i < size_1){
		arr[i+j] = arr_1[i];
		i++;
	}
	while( j < size_2){
		arr[i+j] = arr_2[j];
		j++;
	}
}

