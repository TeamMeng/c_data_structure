#include "AdjacentGraph.h"

static void setupAGraph(AGraph* g) {
  char* nodeNames[] = {"A", "B", "C", "D", "E"};
  initAGraph(g, sizeof(nodeNames) / sizeof(nodeNames[0]), nodeNames, 1);
  addAGraphEdge(g, 0, 4, 1);
  addAGraphEdge(g, 0, 3, 1);
  addAGraphEdge(g, 0, 1, 1);
  addAGraphEdge(g, 1, 4, 1);
  addAGraphEdge(g, 2, 0, 1);
  addAGraphEdge(g, 3, 4, 1);
  addAGraphEdge(g, 3, 2, 1);
}

int main(int argc, char const* argv[]) {
  int n = 5;
  AGraph* g = createAGraph(n);
  setupAGraph(g);
  printf("%d\n", g->edgeNum);
  DFSAGraphTravel(g, 0);
  resetAGraphVisted(g);
  printf("\n");
  BFSAGraphTravel(g, 0);
  releaseAGraph(g);
  return 0;
}
