#include "keyPath.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 通过拓扑排序计算出ETV, 将拓扑排序的结果倒叙来计算LTV
 * stack: 更新入读记录表
 * topOut: 拓扑排序的输出结果, 此结果出栈, 就可以算出从汇点反向计算LTV
 * */

static int topologicalOrder(AGraph *g, int *ETV, int *LTV) {
  int *inDegree = (int *)malloc(sizeof(int) * g->nodeNum);
  if (inDegree == NULL) {
    printf("malloc inDegree failed\n");
    return -1;
  }
  // 1. 初始化图中顶点的入度记录表
  for (int i = 0; i < g->nodeNum; ++i) {
    if (g->nodes[i].firstEdge) {
      ArcEdge *edge = g->nodes[i].firstEdge;
      while (edge) {
        ++inDegree[edge->no];
        edge = edge->next;
      }
    }
  }
  // 2.1 将入度为0的节点入栈, 出栈将判断是否更新ETV
  int *stack = (int *)malloc(sizeof(int) * g->nodeNum);
  int *topOut = (int *)malloc(sizeof(int) * g->nodeNum);
  if (stack == NULL || topOut == NULL) {
    printf("malloc stack or topOut failed\n");
    free(inDegree);
    return -1;
  }
  int top = -1, idx = 0;
  for (int i = 0; i < g->nodeNum; ++i) {
    if (inDegree[i] == 0) {
      stack[++top] = i;
      break;
    }
  }
  // 2.2 不断弹栈, 更新入度记录表
  int tmp;
  while (top != -1) {
    tmp = stack[top--];
    topOut[idx++] = tmp;
    ArcEdge *edge = g->nodes[tmp].firstEdge;
    while (edge) {
      --inDegree[edge->no];
      if (inDegree[edge->no] == 0) {
        stack[++top] = edge->no;
      }
      // 更新 ETV
      if (ETV[tmp] + edge->weight > ETV[edge->no]) {
        ETV[edge->no] = ETV[tmp] + edge->weight;
      }
      edge = edge->next;
    }
  }
  free(stack);
  free(inDegree);
  // 输出topOut
  if (idx < g->nodeNum) { // 无环
    free(topOut);
    return -1;
  }
  // 3. 更新LTV
  // 初始化 LTV
  for (int i = 0; i < g->nodeNum; ++i) {
    LTV[i] = ETV[tmp];
  }
  int getTopNo;
  while (idx) {
    getTopNo = topOut[--idx];
    ArcEdge *edge = g->nodes[getTopNo].firstEdge;
    while (edge) {
      // 后一个节点LTV减去入度边的权值, 和前一个节点最晚发生的时间比较
      if (LTV[edge->no] - edge->weight < LTV[getTopNo]) {
        LTV[getTopNo] = LTV[edge->no] - edge->weight;
      }
      edge = edge->next;
    }
  }
  free(topOut);
  return 0;
}

static void showTable(int *table, int n, const char *name) {
  printf("%s", name);
  for (int i = 0; i < n; ++i) {
    printf("%d\t", table[i]);
  }
  printf("\n");
}

/*
 * 为了求出AOE网中的关键路径, 需要统计4个数据
 * 对于AOE网中顶点有两个时间:
 * ETV: 事件最早发生时间  LTV: 事件最晚发生时间
 * 对于边, 也有两个时间:
 * ETE: 活动最早发生时间  LTE: 活动最晚发生时间
 * 方法:
 * 对于所有的边来说, 它的最早发生时间等于最晚发生时间, 这条边表示为关键路径
 */

void keyPath(AGraph *g) {
  // 1. 计算顶点的ETV和LTV
  int *ETV = (int *)malloc(sizeof(int) * g->nodeNum);
  int *LTV = (int *)malloc(sizeof(int) * g->nodeNum);
  if (ETV == NULL || LTV == NULL) {
    printf("malloc ETV or LTV failed\n");
    return;
  }
  memset(ETV, 0, sizeof(int) * g->nodeNum);
  memset(LTV, 0, sizeof(int) * g->nodeNum);
  // 2. 填充ETV和LTV
  topologicalOrder(g, ETV, LTV);
  showTable(ETV, g->nodeNum, "ETV: ");
  showTable(LTV, g->nodeNum, "LTV: ");
  // 3. 计算ETE和LTE
  for (int i = 0; i < g->nodeNum; ++i) {
    ArcEdge *edge = g->nodes[i].firstEdge;
    while (edge) {
      // 每个边最早发生时间就是边的弧尾的ETV
      // 每个边最晚发生时间就是边的弧头的LTV - 当前边的权值
      if (ETV[i] == LTV[edge->no] - edge->weight) {
        printf("<%s> -- %d -- <%s>\n", g->nodes[i].show, edge->weight,
               g->nodes[edge->no].show);
      }
      edge = edge->next;
    }
  }
  free(ETV);
  free(LTV);
}
