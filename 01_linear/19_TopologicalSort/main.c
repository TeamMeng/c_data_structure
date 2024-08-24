#include "TopologicalSort.h"

#include <stdio.h>

AGraph *setupAGraph1() {
  char *names[] = {"0", "1", "2", "3", "4", "5", "6"};

  int n = sizeof(names) / sizeof(names[0]);

  AGraph *g = createAGraph(n);
  if (g == NULL) {
    return NULL;
  }

  initAGraph(g, n, names, 1);
  addAGraphEdge(g, 0, 1, 1);
  addAGraphEdge(g, 0, 2, 1);
  addAGraphEdge(g, 0, 3, 1);
  addAGraphEdge(g, 1, 2, 1);
  addAGraphEdge(g, 1, 4, 1);
  addAGraphEdge(g, 2, 4, 1);
  addAGraphEdge(g, 2, 5, 1);
  addAGraphEdge(g, 3, 5, 1);
  addAGraphEdge(g, 4, 6, 1);
  addAGraphEdge(g, 5, 4, 1);
  addAGraphEdge(g, 5, 6, 1);

  return g;
}

AGraph *setupAGraph2() {
  char *names[] = {"A", "B", "C", "D", "E"};

  int n = sizeof(names) / sizeof(names[0]);

  AGraph *g = createAGraph(n);
  if (g == NULL) {
    return NULL;
  }

  initAGraph(g, n, names, 1);
  addAGraphEdge(g, 0, 1, 1);
  addAGraphEdge(g, 0, 2, 1);
  addAGraphEdge(g, 1, 3, 1);
  addAGraphEdge(g, 2, 4, 1);
  addAGraphEdge(g, 3, 4, 1);
  addAGraphEdge(g, 4, 1, 1);

  return g;
}

int main(int argc, char *argv[]) {

  AGraph *g1 = setupAGraph1();
  int result = TopologicalSort(g1);
  printf("result is %d\n", result);
  releaseAGraph(g1);

  AGraph *g2 = setupAGraph2();
  result = TopologicalSort(g2);
  printf("result is %d\n", result);
  releaseAGraph(g2);

  return EXIT_SUCCESS;
}
