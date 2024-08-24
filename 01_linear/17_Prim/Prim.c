#include "Prim.h"
#include <stdio.h>
#include <stdlib.h>

int Prim(MGraph *g, int startV, EdgeSet *result) {
  int *cost = (int *)malloc(sizeof(int) * g->nodeNum);
  int *visit = (int *)malloc(sizeof(int) * g->nodeNum);
  int *mark = (int *)malloc(sizeof(int) * g->nodeNum);
  if (cost == NULL || visit == NULL || mark == NULL) {
    printf("malloc failed\n");
    return 0;
  }
  int sum = 0, k, min;

  for (int i = 0; i < g->nodeNum; ++i) {
    cost[i] = g->edges[startV][i];
    mark[i] = 0;
    if (cost[i] < INF) {
      visit[i] = startV;
    } else {
      visit[i] = -1;
    }
  }

  mark[startV] = 1;

  for (int i = 0; i < g->nodeNum - 1; ++i) {
    min = INF;
    for (int j = 0; j < g->nodeNum; ++j) {
      if (mark[j] == 0 && cost[j] < min) {
        min = cost[j];
        k = j;
      }
    }
    mark[k] = 1;
    result[i].begin = visit[k];
    result[i].end = k;
    result[i].weight = min;
    sum += min;
    for (int j = 0; j < g->nodeNum; ++j) {
      if (mark[j] == 0 && g->edges[k][j] < cost[j]) {
        cost[j] = g->edges[k][j];
        visit[j] = k;
      }
    }
  }

  free(cost);
  free(mark);
  free(visit);
  return sum;
}
