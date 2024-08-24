#include "TopologicalSort.h"

#include <string.h>

int TopologicalSort(AGraph *g) {
  int *inDegree = (int *)malloc(sizeof(int) * g->nodeNum);
  if (inDegree == NULL) {
    return -1;
  }
  memset(inDegree, 0, sizeof(int) * g->nodeNum);

  for (int i = 0; i < g->nodeNum; ++i) {
    if (g->nodes[i].firstEdge) {
      ArcEdge *edge = g->nodes[i].firstEdge;
      while (edge) {
        ++inDegree[edge->no];
        edge = edge->next;
      }
    }
  }

  int *stack = (int *)malloc(sizeof(int) * g->nodeNum);
  if (stack == NULL) {
    free(inDegree);
    return -1;
  }
  int top = -1;

  for (int i = 0; i < g->nodeNum; ++i) {
    if (inDegree[i] == 0) {
      stack[++top] = i;
    }
  }

  int count = 0;
  while (top != -1) {
    int index = stack[top--];
    ++count;
    visitAGraphNode(&g->nodes[index]);
    ArcEdge *edge = g->nodes[index].firstEdge;
    while (edge) {
      if (--inDegree[edge->no] == 0) {
        stack[++top] = edge->no;
      }
      edge = edge->next;
    }
  }
  free(inDegree);
  free(stack);
  if (count != g->nodeNum) {
    return 1;
  }
  return 0;
}
