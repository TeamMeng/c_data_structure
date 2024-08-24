#include "swapSort.h"

/* 找最大值, 把最大的放到右边
 * i [0, n - 1) i > i + 1  swap
 * */

void bubbleSortV1(SortTable *table) {
  for (int i = 0; i < table->length; ++i) {
    for (int j = 0; j < table->length - i - 1; ++j) {
      if (table->data[j].key > table->data[j + 1].key) {
        swapElement(&table->data[j], &table->data[j + 1]);
      }
    }
  }
}

void bubbleSortV2(SortTable *table) {
  for (int i = 0; i < table->length; ++i) {
    int isSorted = 1;
    for (int j = 0; j < table->length - i - 1; ++j) {
      if (table->data[j].key > table->data[j + 1].key) {
        swapElement(&table->data[j], &table->data[j + 1]);
        isSorted = 0;
      }
    }
    if (isSorted) {
      break;
    }
  }
}

/*
 * 引入newIndex, 标记最后交换的位置, 下次冒泡排序时, 只需要遍历到这个newIndex
 * 的位置
 * */
void bubbleSortV3(SortTable *table) {
  int newIndex;
  int n = table->length;
  do {
    newIndex = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (table->data[i].key > table->data[i + 1].key) {
        swapElement(&table->data[i], &table->data[i + 1]);
        newIndex = i + 1;
      }
    }
    n = newIndex;
  } while (newIndex > 0);
}
