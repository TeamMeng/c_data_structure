#include "quickSort.h"

#include <stdlib.h>
#include <time.h>

/* 单边循环法，设置一个mark标记，表示小于基准元素的区域边界
 * 1. 从基准元素的下一个位置开始遍历数组
 * 2. 如果遍历到的元素大于基准元素，就继续向后遍历
 * 3. 如果遍历到的元素小于基准元素
 * 	3.1 把mark++
 * 	3.2 把当前mark的值（大于基准元素）和找出来小的值交换
 * 4. 最后把mark和基准元素交换位置
 * */
static int partitionSingle(SortTable *table, int start, int end) {
  keyType tmp = table->data[start].key;
  int mark = start;
  for (int i = start + 1; i <= end; ++i) {
    if (table->data[i].key < tmp) {
      mark++;
      swapElement(&table->data[mark], &table->data[i]);
    }
  }
  swapElement(&table->data[mark], &table->data[start]);
  return mark;
}

/* 双边循环
 * 1. 设置左, 右标记, 基准点认为最左边的元素
 * 2. 先从右标记, 让right标记指向的元素和基准元素比较, 如果大于pivot, 则左移
 *  如果小, 则停止right标记移动, 切换到left标记移动
 * 3. 在left标记中, 如果小于基准, 则右移, 如果大于基准, 那么left标记停止移动
 * 4. 此时交换左右的值
 * 5. 接下来继续第二轮循环
 * 6. 最后, 当left和right相等时, 基准就找到了, 那么将基准值放入这个位置
 * */
static int partitionDouble(SortTable *table, int startIndex, int endIndex) {
  int pivot = startIndex;
  int left = startIndex;
  int right = endIndex;
  srand(time(NULL) + 1);
  swapElement(&table->data[startIndex],
              &table->data[rand() % (endIndex - startIndex) + startIndex]);
  while (left != right) {
    while (left < right && table->data[right].key > table->data[pivot].key)
      right--;
    while (left < right && table->data[left].key <= table->data[pivot].key)
      left++;
    if (left < right) {
      swapElement(&table->data[right], &table->data[left]);
    }
  }
  swapElement(&table->data[pivot], &table->data[left]);
  return left;
}

static void V1(SortTable *table, int start, int end) {
  if (start >= end) {
    return;
  }
  int pivot = partitionDouble(table, start, end);
  V1(table, start, pivot - 1);
  V1(table, pivot + 1, end);
}

static void V2(SortTable *table, int start, int end) {
  if (start >= end) {
    return;
  }
  int pivot = partitionSingle(table, start, end);
  V2(table, start, pivot - 1);
  V2(table, end, pivot + 1);
}

void quickSortV1(SortTable *table) { V1(table, 0, table->length - 1); }

void quickSortV2(SortTable *table) { V2(table, 0, table->length - 1); }
