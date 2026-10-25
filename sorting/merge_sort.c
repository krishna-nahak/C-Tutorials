#include <stdio.h>


void merge(int* arr, int lb, int mid, int ub) {
  int lsize = mid-lb+1;
  int rsize = ub-mid;

  int left[lsize];
  int right[rsize];

  for(int i=0; i<lsize; i++) {
    left[i] = arr[lb+i];
  }

  for(int i=0; i<rsize; i++) {
    right[i] = arr[mid+1+i];
  }


  int i = 0,j = 0,k = lb;
  while(i < lsize && j < rsize) {
    if(left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }

  while(i < lsize) {
    arr[k++] = left[i++];
  }

  while(j < rsize) {
    arr[k++] = right[j++];
  }

}

void merge_sort(int* arr, int ub, int lb){
  if(ub > lb) {

    int mid = (ub+lb) / 2;
    merge_sort(arr, mid, lb);
    merge_sort(arr, mid+1, ub);

    // final merging
    merge(arr, lb, mid, ub);
  }
}



int main() {

  int nums[] = {90, 2, 1, -2, 100};
  int size = sizeof(nums) / sizeof(nums[0]);

  merge_sort(nums, size-1, 0);
  for(int i=0; i<size; i++) {
    printf("%d -> ", nums[i]);
  }

  return 0;
}