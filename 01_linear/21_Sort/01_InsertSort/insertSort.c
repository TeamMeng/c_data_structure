#include "insertSort.h"

/*
    1. 默认第一个元素有序, 那么第二个元素开始和前面有序区域比较
    2. 待插入的元素i, 和有序区域从后往前依次查找
       若带插入元素 < 以有序区域的值, 有序的区域的值后移一位
       插入查找的位置[0..i - 1]的位置
*/
void insertSort(SortTable *table) {
  for (int i = 1; i < table->length; ++i) {
    if (table->data[i].key < table->data[i - 1].key) {
      int j = i - 1;
      Element tmp = table->data[i];
      while (tmp.key < table->data[j].key && j > -1) {
        table->data[j + 1] = table->data[j];
        --j;
      }
      table->data[j + 1] = tmp;
    }
  }
}

void insertSortV1(SortTable *table) {
  for (int i = 1; i < table->length; ++i) {  // i 去遍历无序的区域
    // 每个无序区域里的值，不断的和前面元素进行交换
    Element e = table->data[i];
    int j;
    for (j = i; j > 0 && table->data[j - 1].key > e.key; --j) {
      swapElement(&table->data[j], &table->data[j - 1]);
    }
    table->data[j] = e;
  }
}

void shellSort(SortTable *table) {
  int gap;
  // gap为步长，每次减少一半
  for (gap = table->length / 2; gap > 0;
       gap /= 2) {  // 对每个步长分别进行插入排序
    // 共gap个组，每一组都执行插入排序
    for (int i = gap; i < table->length; ++i) {
      Element temp = table->data[i];
      int j;
      for (j = i; j >= gap && table->data[j - gap].key > temp.key; j -= gap) {
        swapElement(&table->data[j], &table->data[j - gap]);
      }
      table->data[j] = temp;
    }
  }
}