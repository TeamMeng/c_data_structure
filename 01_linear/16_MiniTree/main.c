#include "Kruskal.h"

#include <stdio.h>
#include <stdlib.h>

static void setUpMGraph(MGraph *g) {
  char *names[] = {"A", "B", "C", "D", "E", "F", "G"};
  initMGraph(g, sizeof(names) / sizeof(names[0]), names, 0, 0);
  addMGraphEdge(g, 0, 1, 12);
  addMGraphEdge(g, 0, 6, 14);
  addMGraphEdge(g, 0, 5, 16);
  addMGraphEdge(g, 1, 2, 10);
  addMGraphEdge(g, 1, 5, 7);
  addMGraphEdge(g, 2, 3, 3);
  addMGraphEdge(g, 2, 4, 5);
  addMGraphEdge(g, 2, 5, 6);
  addMGraphEdge(g, 3, 4, 4);
  addMGraphEdge(g, 4, 5, 2);
  addMGraphEdge(g, 4, 6, 8);
  addMGraphEdge(g, 5, 6, 9);
}

int main(int argc, char *argv[]) {
  MGraph g;
  setUpMGraph(&g);

  EdgeSet *edges;
  edges = (EdgeSet *)malloc(sizeof(EdgeSet) * g.edgeNum);

  int num = initEdgeSet(&g, edges);
  printf("edgeSet num: %d\n", num);
  sortEdgeSet(edges, num);

  EdgeSet *result = (EdgeSet *)malloc(sizeof(EdgeSet) * (g.nodeNum - 1));
  int sumW = KruskalMGraph(&g, edges, num, result);

  printf("Kruskal sum of weight: %d\n", sumW);
  for (int i = 0; i < g.nodeNum - 1; ++i) {
    printf("edge %d: [%s] --- <%d> --- [%s]\n", i + 1,
           g.vec[result[i].begin].show, result[i].weight,
           g.vec[result[i].end].show);
  }

  free(edges);
  free(result);

  return EXIT_SUCCESS;
}
