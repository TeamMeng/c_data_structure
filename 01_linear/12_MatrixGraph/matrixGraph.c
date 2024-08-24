#include "matrixGraph.h"

int isEdge(int weight) {
  if (weight > 0 && weight < INF) {
    return 1;
  }
  return 0;
}

void initMGraph(MGraph* g, int num, char* names[], int directed,
                int edgeValue) {
  g->directed = directed;
  g->edgeNum = 0;
  g->nodeNum = num;
  memset(g->vec, 0, sizeof(g->vec));
  memset(g->edges, 0, sizeof(MatrixEdge) * MaxNodeNum * MaxNodeNum);
  for (int i = 0; i < num; ++i) {
    g->vec[i].no = i;
    g->vec[i].show = names[i];
    for (int j = 0; j < num; ++j) {
      g->edges[i][j] = edgeValue;
    }
  }
}

void addMGraphEdge(MGraph* g, int x, int y, int w) {
  if (x < 0 || x > g->nodeNum || y < 0 || y > g->nodeNum) {
    return;
  }
  if (!isEdge(g->edges[x][y])) {
    g->edges[x][y] = w;
    if (g->directed == 0) {
      g->edges[y][x] = w;
    }
    g->edgeNum++;
  }
}

void visitMGraphNode(MatrixVertex* node) { printf("%s\t", node->show); }

static int MGraphVisited[MaxNodeNum];

void clearMGraphVisit() { memset(MGraphVisited, 0, sizeof(MGraphVisited)); }

void DFSMGraphTravel(MGraph* g, int v) {
  visitMGraphNode(&g->vec[v]);
  MGraphVisited[v] = 1;
  for (int i = 0; i < g->nodeNum; ++i) {
    if (isEdge(g->edges[v][i]) && MGraphVisited[i] == 0) {
      DFSMGraphTravel(g, i);
    }
  }
}

void BFSMGraphTravel(MGraph* g, int v) {
  int que[MaxNodeNum];
  int rear = 0, front = 0;
  int cur = 0;

  rear = (rear + 1) % MaxNodeNum;
  que[rear] = v;
  while (front != rear) {
    front = (front + 1) % MaxNodeNum;
    cur = que[front];
    visitMGraphNode(&g->vec[cur]);
    MGraphVisited[cur] = 1;
    for (int i = 0; i < g->nodeNum; ++i) {
      if (isEdge(g->edges[cur][i]) && MGraphVisited[i] == 0) {
        rear = (rear + 1) % MaxNodeNum;
        que[rear] = i;
        MGraphVisited[i] = 1;
      }
    }
  }
}
