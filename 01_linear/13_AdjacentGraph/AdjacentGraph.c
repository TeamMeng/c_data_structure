#include "AdjacentGraph.h"

AGraph* createAGraph(int n) {
  AGraph* g = (AGraph*)malloc(sizeof(AGraph));
  if (g == NULL) {
    fprintf(stderr, "malloc failed\n");
    return NULL;
  }

  g->edgeNum = 0;
  g->nodeNum = n;
  g->nodes = (ArcNode*)malloc(sizeof(ArcNode) * n);
  g->visited = (int*)malloc(sizeof(int) * n);
  if (g->nodes == NULL || g->visited == NULL) {
    fprintf(stderr, "malloc node or visited failed\n");
    free(g);
    return NULL;
  }

  memset(g->nodes, 0, sizeof(ArcNode) * n);
  return g;
}

void releaseAGraph(AGraph* g) {
  if (g) {
    int count = 0;
    for (int i = 0; i < g->nodeNum; ++i) {
      ArcEdge* edge = g->nodes[i].firstEdge;
      while (edge) {
        ArcEdge* tmp = edge;
        edge = tmp->next;
        free(tmp);
        count++;
      }
    }
    if (g->visited) {
      free(g->visited);
    }
    if (g->nodes) {
      free(g->nodes);
    }
    free(g);
    printf("release %d edges\n", count);
  }
}

void initAGraph(AGraph* g, int num, char* names[], int directed) {
  g->directed = directed;
  for (int i = 0; i < num; ++i) {
    g->nodes[i].no = i;
    g->nodes[i].show = names[i];
    g->nodes[i].firstEdge = NULL;
  }
}

static ArcEdge* createArcEdge(int v, int w) {
  ArcEdge* edge = (ArcEdge*)malloc(sizeof(ArcEdge));
  edge->no = v;
  edge->weight = w;
  edge->next = NULL;
  return edge;
}

void addAGraphEdge(AGraph* graph, int x, int y, int w) {
  if (x < 0 || x >= graph->nodeNum || y < 0 || y >= graph->nodeNum) {
    return;
  }
  if (x == y) {
    return;
  }
  ArcEdge* edge = createArcEdge(y, w);
  edge->next = graph->nodes[x].firstEdge;
  graph->nodes[x].firstEdge = edge;
  graph->edgeNum++;
  if (graph->directed == 0) {
    edge = createArcEdge(x, w);
    edge->next = graph->nodes[y].firstEdge;
    graph->nodes[y].firstEdge = edge;
    graph->edgeNum++;
  }
}

void visitAGraphNode(ArcNode* node) { printf("%s\t", node->show); }

void DFSAGraphTravel(AGraph* g, int v) {
  ArcEdge* p;
  g->visited[v] = 1;
  visitAGraphNode(&g->nodes[v]);
  p = g->nodes[v].firstEdge;
  while (p) {
    if (g->visited[p->no] == 0) {
      DFSAGraphTravel(g, p->no);
    }
    p = p->next;
  }
}

void BFSAGraphTravel(AGraph* g, int v) {
  int* que = (int*)malloc(sizeof(int*) * g->nodeNum);
  int front = 0, rear = 0;
  int cur;
  ArcEdge* p;

  rear = (rear + 1) % g->nodeNum;
  que[rear] = v;
  while (front != rear) {
    front = (front + 1) % g->nodeNum;
    cur = que[front];
    visitAGraphNode(&g->nodes[cur]);
    g->visited[cur] = 1;
    p = g->nodes[cur].firstEdge;
    while (p) {
      if (g->visited[p->no] == 0) {
        rear = (rear + 1) % g->nodeNum;
        que[rear] = p->no;
        g->visited[p->no] = 1;
      }
      p = p->next;
    }
  }
  free(que);
}

void resetAGraphVisted(AGraph* g) {
  if (g && g->visited) {
    memset(g->visited, 0, sizeof(int) * g->nodeNum);
  }
}
