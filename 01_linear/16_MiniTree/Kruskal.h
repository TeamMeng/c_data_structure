#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../12_MatrixGraph/matrixGraph.h"

#define MaxNodeNum 10
#define Inf 10

typedef struct {
  int begin;
  int end;
  int weight;
} EdgeSet;

int initEdgeSet(MGraph *g, EdgeSet *edgeSet);

void sortEdgeSet(EdgeSet *edgeSet, int num);

int KruskalMGraph(const MGraph *g, const EdgeSet *edges, int num,
                  EdgeSet *result);

#endif // !KRUSKAL_H
