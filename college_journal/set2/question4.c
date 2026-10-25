#include <stdio.h>

void display(int* arr, int n) {
	if(n <= 0) 
		printf("[ ]\n");

	printf("[");
	for(int i=0; i<n-1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d]\n", arr[n-1]);
}

void merge(int* arr1, int* arr2, int size1, int size2) {

	int totLen = size1 + size2;
	int aux[totLen];

	int i, j, k;
	i=j=k=0;

	while(i < size1) {
		aux[k++] = arr1[i++];
	}

	while(j < size2) {
		aux[k++] = arr2[j++];
	}

	display(aux, totLen);
}

int main() {
	int arr1[5] = {23, 34, 100, 11, 0};
	int arr2[6] = {34, 345, 543, 9, 900, 121};

	merge(arr1, arr2, 5, 6);
	return 0;
}