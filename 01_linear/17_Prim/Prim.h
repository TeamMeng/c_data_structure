#ifndef PRIM_H
#define PRIM_H

#include "../12_MatrixGraph/matrixGraph.h"

typedef struct {
  int begin;
  int end;
  int weight;
} EdgeSet;

int Prim(MGraph *g, int startV, EdgeSet *result);

#endif // !PRIM_H
