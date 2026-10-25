#include <stdio.h>
#include <stdlib.h>

void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubble_sort(int *nums, int size) {
	for (int i = 0; i<size - 1; i++) {
		for (int j = i+1; j<size; j++) {
			if (nums[i] > nums[j]) {
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
			}
		}
	}
}

void selection_sort(int *nums, int size) {
	int min_idx;

	for (int i = 0; i<size - 1; i++) {

		min_idx = i;
		for (int j = i+1; j<size; j++) {
			if(nums[min_idx] > nums[j]) 
				min_idx = j;
		}

		//. swapping
		if(min_idx != i) {
			int temp = nums[min_idx];
			nums[min_idx] = nums[i];
			nums[i] = temp;
		}
	}
}

void insertion_sort(int *nums, int size) {
	int j;

	for(int i=1; i<size; i++) {
		j=i-1;
		int key = nums[i];

		while(j>=0 && key < nums[j]) {
			nums[j+1] = nums[j];
			j--;
		}

		nums[j+1] = key;
	}
}

int partition(int* nums, int st, int end) {
	int pivotIdx = end;
	int idx = st-1;

	for(int j=st; j<end; j++) {
		if(nums[j] < nums[pivotIdx]) {
			idx++;
			swap(&nums[idx], &nums[j]);
		}
	}

	idx++;
	swap(&nums[idx], &nums[pivotIdx]);
	return idx;
}

void quick_sort(int* nums, int st, int end) {
	if(st < end) {
		int pivotIdx = partition(nums, st, end);
		quick_sort(nums, st, pivotIdx-1);
		quick_sort(nums, pivotIdx+1, end);
	}
}

void merge(int* nums, int st, int mid, int end) {
	int lSize = (mid-st+1), rSize = (end-mid);
	int size = end - st + 1;
	int left[lSize], right[rSize];

	for(int i=0; i<lSize; i++) {
		left[i] = nums[st+i];
	}

	for(int i=0; i<rSize; i++) {
		right[i] = nums[mid+1+i];
	}

	int i = 0, j = 0, k = st;
	while(i < lSize && j < rSize) {
		if(left[i] <= right[j]) {
			nums[k++] = left[i++];
		} else {
			nums[k++] = right[j++];
		}
	}

	while(i < lSize) {
		nums[k++] = left[i++];
	}

	while(j < rSize) {
		nums[k++] = right[j++];
	}
}

void merge_sort(int* nums, int st, int end) {
	if(st < end) {
		int mid = (st + end) / 2;
		merge_sort(nums, st, mid);
		merge_sort(nums, mid+1, end);
		merge(nums, st, mid, end);
	}
}


// 1. bucket sort also known as bin sort.
// 2. Count sort is frequency based technique.


int get_max(int* arr, int size) {
	int mx = arr[0];

	for(int i=1; i<size; i++) 
		if(mx < arr[i]) 
			mx = arr[i];
	
	return mx;
}

void bucket_sort(int* arr, int n, int exp) {
	int* bucket[10] = {NULL};

	for(int i=0; i<n; i++) {
		int currSize = (sizeof(*bucket[i]) / sizeof(bucket[i][0]));
		int bucketIdx = (arr[i]/exp) % 10;
		bucket[i] = realloc(bucket[bucketIdx], ++currSize);

		bucket[bucketIdx][currSize] = arr[i];
	}

	int k=0;
	for(int i=0; i<10; i++) {

		int bucketSize = (sizeof(*bucket[i]) / sizeof(bucket[i][0]));
		for(int j=0; j<bucketSize; j++) {
			arr[k++] = bucket[i][j];
		}
	}
}

void count_sort(int* arr, int n, int exp) {
	int output[n];
	int count[10] = {0};

	for(int i=0; i<n; i++) {
		count[ abs((arr[i] / exp) % 10) ]++;
	}

	for(int i=1; i<10; i++) {
		count[i] += count[i-1];
	}

	for(int i=n-1; i>=0; i--) {
		output[count[ abs((arr[i]/exp) % 10) ] - 1] = arr[i];
		count[abs((arr[i]/exp) % 10)]--;
	}

	for(int i=0; i<n; i++) {
		arr[i] = output[i];
	}
}

void radix_sort(int* nums, int size, int choice) {

	int max = get_max(nums, size);

	for(int exp = 1; (max/exp) > 0; exp *= 10) {
		if(choice == 1) 
			count_sort(nums, size, exp);
		else 
			bucket_sort(nums, size, exp);
	}
}


void display(int* arr, int n) {
	if(n <= 0) 
		printf("[ ]\n");

	printf("[");
	for(int i=0; i<n-1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d]\n", arr[n-1]);
}

int main() {

	int nums[] = {200, 1, 0, -1, 200, 230, 100, 10000};
	int n = sizeof(nums) / sizeof(nums[0]);

	printf("Choose a sorting technique\n");
	printf("1. Bubble Sort\n");
	printf("2. Selection Sort\n");
	printf("3. Insertion Sort\n");
	printf("4. Merge Sort\n");
	printf("5. Quick Sort\n");
	printf("6. Radix Sort using Buckets\n");
	printf("7. Radix Sort using Count technique\n");
	

	int choice;
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch(choice) {
		case 1:
			bubble_sort(nums, n);
			break;

		case 2:
			selection_sort(nums, n);
			break;

		case 3:
			insertion_sort(nums, n);
			break;

		case 4:
			merge_sort(nums, 0, n-1);
			break;

		case 5:
			quick_sort(nums, 0, n-1);
			break;

		case 6:
			radix_sort(nums, n, 0);
			break;

		case 7:
			radix_sort(nums, n, 1);
			break;

		default:
			printf("Invalid choice\n");
	}


	display(nums, n);
	return 0;
}