#include "insertSort.h"

int main(int argc, char const* argv[]) {
  int n = 100000;
  SortTable* table1 = generateRandomArray(n, 0, n);
  SortTable* table2 = copySortTable(table1);
  SortTable* table3 = copySortTable(table1);
  SortTable* table4 = generateLinearArray(n, 10);

  testSort("random insert: ", insertSortV1, table1);
  testSort("random insert: ", insertSort, table2);
  testSort("shell insert: ", shellSort, table3);
  testSort("random insert: ", insertSort, table4);
  releaseSortTable(table1);
  releaseSortTable(table2);
  releaseSortTable(table3);
  releaseSortTable(table4);

  return 0;
}
