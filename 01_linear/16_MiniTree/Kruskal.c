#include "Kruskal.h"

#include <string.h>

int initEdgeSet(MGraph *g, EdgeSet *edgeSet) {
  int k = 0;
  for (int i = 0; i < g->nodeNum; ++i) {
    for (int j = i + 1; j < g->nodeNum; ++j) {
      if (g->edges[i][j] > 0) {
        edgeSet[k].begin = i;
        edgeSet[k].end = j;
        edgeSet[k].weight = g->edges[i][j];
        k++;
      }
    }
  }
  return k;
}

void sortEdgeSet(EdgeSet *edgeSet, int num) {
  EdgeSet tmp;
  for (int i = 0; i < num; ++i) {
    for (int j = i + 1; j < num; ++j) {
      if (edgeSet[i].weight > edgeSet[j].weight) {
        memcpy(&tmp, &edgeSet[i], sizeof(EdgeSet));
        memcpy(&edgeSet[i], &edgeSet[j], sizeof(EdgeSet));
        memcpy(&edgeSet[j], &tmp, sizeof(EdgeSet));
      }
    }
  }
}

static int getRoot(const int *uSet, int a) {
  while (a != uSet[a]) {
    a = uSet[a];
  }
  return a;
}

int KruskalMGraph(const MGraph *g, const EdgeSet *edges, int num,
                  EdgeSet *result) {
  int a, b, count = 0, w = 0;
  int *uSet = (int *)malloc(sizeof(int) * g->nodeNum);
  for (int i = 0; i < g->nodeNum; ++i) {
    uSet[i] = i;
  }

  for (int i = 0; count < g->nodeNum - 1 && i < num; ++i) {
    a = getRoot(uSet, edges[i].begin);
    b = getRoot(uSet, edges[i].end);
    if (a != b) {
      uSet[a] = b;
      result[count].begin = edges[i].begin;
      result[count].end = edges[i].end;
      result[count].weight = edges[i].weight;
      count++;
      w += edges[i].weight;
    }
  }

  free(uSet);
  return w;
}
