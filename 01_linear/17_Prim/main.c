#include "Prim.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  MGraph graph;
  char *names[] = {"A", "B", "C", "D", "E", "F", "G"};
  initMGraph(&graph, sizeof(names) / sizeof(names[0]), names, 0, INF);
  addMGraphEdge(&graph, 0, 1, 12);
  addMGraphEdge(&graph, 0, 5, 16);
  addMGraphEdge(&graph, 0, 6, 14);
  addMGraphEdge(&graph, 1, 2, 10);
  addMGraphEdge(&graph, 1, 5, 7);
  addMGraphEdge(&graph, 2, 3, 3);
  addMGraphEdge(&graph, 2, 4, 5);
  addMGraphEdge(&graph, 2, 5, 6);
  addMGraphEdge(&graph, 3, 4, 4);
  addMGraphEdge(&graph, 4, 5, 2);
  addMGraphEdge(&graph, 4, 6, 8);
  addMGraphEdge(&graph, 5, 6, 9);

  EdgeSet *result = (EdgeSet *)malloc(sizeof(EdgeSet) * graph.nodeNum);
  if (result == NULL) {
    printf("malloc failed\n");
    return 0;
  }

  int sum = Prim(&graph, 0, result);
  printf("Prim sum of weight: %d\n", sum);
  for (int i = 0; i < graph.nodeNum - 1; ++i) {
    printf("edge %d: [%s] --- <%d> --- [%s]\n", i + 1,
           graph.vec[result[i].begin].show, result[i].weight,
           graph.vec[result[i].end].show);
  }

  free(result);
  return EXIT_SUCCESS;
}
