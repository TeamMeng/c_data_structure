#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNodeNum 10

#define INF 1E5

typedef struct {
  int no;
  char* show;
} MatrixVertex;

typedef int MatrixEdge;

typedef struct {
  MatrixVertex vec[MaxNodeNum];
  int nodeNum;
  MatrixEdge edges[MaxNodeNum][MaxNodeNum];
  int edgeNum;
  int directed;
} MGraph;

void initMGraph(MGraph* g, int num, char* name[], int directed, int edgeValue);

void addMGraphEdge(MGraph* g, int x, int y, int w);

void visitMGraphNode(MatrixVertex* node);

void clearMGraphVisit();

void DFSMGraphTravel(MGraph* g, int v);

void BFSMGraphTravel(MGraph* g, int v);