#include "miniHeap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 满足节点的访问行为 [i/2, i, 2i, 2i + 1] 根节点从1号索引进行存储
 * */
MiniHeap *createMiniHeap(int n) {
  MiniHeap *heap = (MiniHeap *)malloc(sizeof(MiniHeap));
  if (heap == NULL) {
    fprintf(stderr, "malloc mini heap failed\n");
    return NULL;
  }

  heap->data = (keyType *)malloc(sizeof(keyType) * (n + 1));
  if (heap->data == NULL) {
    fprintf(stderr, "malloc key type failed\n");
    free(heap);
    return NULL;
  }

  memset(heap->data, 0, sizeof(keyType) * (n + 1));

  heap->capacity = n;
  heap->len = 0; // 每次插入元素先加一, 再插入

  return heap;
}

void releaseMiniHeap(MiniHeap *heap) {
  if (heap) {
    if (heap->data) {
      free(heap->data);
    }
    free(heap);
  }
}

/* 先在最后位置插入元素, 然后通过上移操作, 确定这个新元素的位置,
 * 保证每个根节点是子节点的最小值
 * */

static void shiftUp(MiniHeap *heap, int k) {
  while (k > 1 && heap->data[k / 2] > heap->data[k]) {
    keyType t = heap->data[k];
    heap->data[k] = heap->data[k / 2];
    heap->data[k / 2] = t;
    k /= 2;
  }
}

void insertMiniHeap(MiniHeap *heap, keyType e) {
  if (heap->len + 1 > heap->capacity) {
    printf("MiniHeap space is full\n");
    return;
  }
  heap->data[++heap->len] = e;
  // 上移
  shiftUp(heap, heap->len);
}

static void shiftDown(MiniHeap *heap, int k) {
  while (k * 2 <= heap->len) {
    int idx = 2 * k;
    // 如果有右孩子, 右孩子和左孩子比较, 右小更新
    if (idx + 1 <= heap->len && heap->data[idx + 1] < heap->data[idx]) {
      idx += 1;
    }
    if (heap->data[k] > heap->data[idx]) {
      keyType t = heap->data[k];
      heap->data[k] = heap->data[idx];
      heap->data[idx] = t;
      k = idx;
    } else {
      break;
    }
  }
}

keyType extractMiniHeap(MiniHeap *heap) {
  if (heap->len <= 0) {
    printf("No data\n");
    return -1;
  }
  keyType ret = heap->data[1];
  heap->data[1] = heap->data[heap->len--];
  shiftDown(heap, 1);

  return ret;
}
