#include <stdio.h>

#include "adjacencyMultiLish.h"

int main(int argc, char const* argv[]) {
  AdjacencyMultiList* g = createMultiList(5);
  char* names[] = {"A", "B", "C", "D", "E"};
  initMultiList(g, 5, names);
  insertMultiListEdge(g, 0, 1, 1);
  insertMultiListEdge(g, 0, 3, 1);
  insertMultiListEdge(g, 2, 1, 1);
  insertMultiListEdge(g, 2, 3, 1);
  insertMultiListEdge(g, 4, 2, 1);
  insertMultiListEdge(g, 4, 3, 1);
  return 0;
}
