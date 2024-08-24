#ifndef DIJKSTRA_SHORT_PATH_H
#define DIJKSTRA_SHORT_PATH_H

#include "../12_MatrixGraph/matrixGraph.h"

void DijkstraMGraph(const MGraph* g, int start, int dist[] ,int path[]);

void showShortPath(const int path[], int num, int pos);

#endif