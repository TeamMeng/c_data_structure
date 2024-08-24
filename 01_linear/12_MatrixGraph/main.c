#include "matrixGraph.h"

static void setupMatrixGraph(MGraph* g) {
  char* nodeNames[] = {"V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8"};
  initMGraph(g, 8, nodeNames, 0, 0);
  addMGraphEdge(g, 0, 1, 1);
  addMGraphEdge(g, 0, 2, 1);
  addMGraphEdge(g, 1, 3, 1);
  addMGraphEdge(g, 1, 4, 1);
  addMGraphEdge(g, 2, 5, 1);
  addMGraphEdge(g, 2, 6, 1);
  addMGraphEdge(g, 5, 6, 1);
  addMGraphEdge(g, 3, 7, 1);
  addMGraphEdge(g, 4, 7, 1);
}

int main(int argc, char const* argv[]) {
  MGraph g;
  setupMatrixGraph(&g);

  printf("have %d num\n", g.edgeNum);
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      printf("%d\t", g.edges[i][j]);
    }
    printf("\n");
  }

  clearMGraphVisit();
  DFSMGraphTravel(&g, 0);
  printf("\n");

  clearMGraphVisit();
  BFSMGraphTravel(&g, 0);
  return 0;
}
