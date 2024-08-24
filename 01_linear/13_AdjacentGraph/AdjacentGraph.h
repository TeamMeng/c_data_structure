#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNodeNum 10

#define INF 1E5

typedef struct arcEdge {
  int no;
  int weight;
  struct arcEdge* next;
} ArcEdge;

typedef struct {
  int no;
  char* show;
  ArcEdge* firstEdge;
} ArcNode;

typedef struct {
  ArcNode* nodes;
  int* visited;
  int nodeNum;
  int edgeNum;
  int directed;
} AGraph;

AGraph* createAGraph(int n);

void releaseAGraph(AGraph* g);

void initAGraph(AGraph* g, int num, char* names[], int directed);

void addAGraphEdge(AGraph* graph, int x, int y, int w);

void visitAGraphNode(ArcNode* node);

void DFSAGraphTravel(AGraph* g, int v);

void BFSAGraphTravel(AGraph* g, int v);

void resetAGraphVisted(AGraph* g);