#ifndef CROSS_LINK_GRAPH_H
#define CROSS_LINK_GRAPH_H
typedef struct arcBox {
  int tailVertex;           
  struct arcBox *tailNext;  
  int headVertex;           
  struct arcBox *headNext; 
  int weight;             
} ArcBox;

typedef struct {
  int no;
  const char *show;
  ArcBox *firstIn;   
  ArcBox *firstOut; 
} CrossVertex;

typedef struct {
  CrossVertex *nodes;
  int numVertex;
  int numEdge;
} CrossGraph;

CrossGraph *createCrossGraph(int n);

void releaseCrossGraph(CrossGraph *graph);

void initCrossGraph(CrossGraph *graph, int num, char *names[]);

void addCrossArc(CrossGraph *graph, int tail, int head, int w);

int inDegreeCrossGraph(CrossGraph *graph, int no);

int outDegreeCrossGraph(CrossGraph *graph, int no);
#endif
