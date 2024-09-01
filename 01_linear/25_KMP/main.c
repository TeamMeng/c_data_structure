#include "findStr.h"
#include <stdio.h>
#include <stdlib.h>

void test01(StrType *str, StrType *substr) {
  int index = index_simple(str, substr);
  printf("idx: %d\n", index);
}

void test02(StrType *str, StrType *subStr) {
  int *next = (int *)malloc(sizeof(int) * (subStr->length + 1));
  getNext(subStr, next);
  int idx = indexKMP(str, subStr, next);
  printf("idx: %d\n", idx);
  free(next);
}

int main(int argc, char *argv[]) {
  StrType str;
  StrType subStr;
  str.str = subStr.str = NULL;

  strAssign(&str, "ABCDABCABCABABCABCDA");
  strAssign(&subStr, "ABCABCD");

  test01(&str, &subStr);
  test02(&str, &subStr);
  releaseStr(&str);
  releaseStr(&subStr);

  return EXIT_SUCCESS;
}
