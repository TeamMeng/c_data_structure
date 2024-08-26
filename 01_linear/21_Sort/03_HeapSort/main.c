#include "HeaSort.h"
#include "miniHeap.h"
#include <stdio.h>

void test01() {
  int data[] = {9, 3, 7, 6, 5, 1, 10, 2};
  MiniHeap *heap = createMiniHeap(20);
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
    insertMiniHeap(heap, data[i]);
  }
  printf("array: ");
  for (int i = 1; i <= heap->len; ++i) {
    printf("%d\t", heap->data[i]);
  }
  printf("\n");
  keyType tmp = extractMiniHeap(heap);
  while (tmp != -1) {
    printf("%d\t", tmp);
    tmp = extractMiniHeap(heap);
  }
  printf("\n");
  releaseMiniHeap(heap);
}

// 随机排序表的堆排序测试

void test02() {
  int n = 1000000;
  SortTable *table = generateRandomArray(n, 0, n);
  testSort("HeapSort: ", miniHeapSort, table);
  releaseSortTable(table);
}

int main(int argc, char *argv[]) {
  test01();
  test02();
  return EXIT_SUCCESS;
}
