#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ELement;

/* 二分查找
 * 数组空间有序, 在闭区间搜索, 就是不断确定范围[0..n - 1]
 * 确定left和right的区间, 定位mid值, 根据mid值和待查找的值的关系更新left和right
 * */

int binarySearch(const ELement *arr, int n, ELement target) {
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int mid = (right - left) / 2 + left;
    if (arr[mid] > target) {
      right = mid - 1;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int normalSearch(const ELement *arr, int n, ELement target) {
  for (int i = 0; i < n; ++i) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

ELement *generateOrderArray(int n) {
  ELement *arr = (ELement *)malloc(sizeof(ELement) * n);
  if (arr == NULL) {
    fprintf(stderr, "malloc failed\n");
    return NULL;
  }
  for (int i = 0; i < n; ++i) {
    arr[i] = i;
  }
  return arr;
}

int main(int argc, char *argv[]) {
  int n = 10000;
  ELement *arr = generateOrderArray(n);
  if (arr == NULL) {
    return -1;
  }
  clock_t start = clock();
  for (int i = 0; i < n; ++i) {
    if (binarySearch(arr, n, n + 10) != -1) {
      printf("binary search failed\n");
    }
  }
  clock_t end = clock();
  printf("Time cost %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
  start = clock();
  for (int i = 0; i < n; ++i) {
    if (normalSearch(arr, n, n + 10) != -1) {
      printf("binary search failed\n");
    }
  }
  end = clock();
  printf("Time cost %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
  free(arr);
  return EXIT_SUCCESS;
}
