




void swap(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void sort(int arr[], int size){
	for(int i = 0; i < size; i++){
		for (int j = i + 1; j < size; j++){
			if(arr[j] < arr[i]){
				// arr[i] = arr[i] + arr[j];
				// arr[j] = arr[i] - arr[j];
				// arr[i] = arr[i] - arr[j];
				swap(&arr[i], &arr[j]);
			}
		}
	}
}
