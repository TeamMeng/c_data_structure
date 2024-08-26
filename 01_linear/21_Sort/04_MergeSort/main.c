#include "mergSort.h"

int main(int argc, char *argv[]) {
  int n = 1000000;
  SortTable *table = generateRandomArray(n, 0, n);
  testSort("Merg Sort: ", mergeSort, table);
  releaseSortTable(table);
  return EXIT_SUCCESS;
}
