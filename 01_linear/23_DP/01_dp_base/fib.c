#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int fib01(unsigned int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fib01(n - 1) + fib01(n - 2);
}

void test01() {
  clock_t start = clock();
  int n = fib01(50);
  printf("%d\n", n);
  clock_t end = clock();
  printf("cost time: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
}

// 记忆化搜索
static unsigned int *mem01;

unsigned int fib02(unsigned int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (mem01[n] == -1) {
    mem01[n] = fib02(n - 1) + fib02(n - 2);
  }
  return mem01[n];
}

void test02() {
  int n = 50;
  mem01 = (unsigned int *)malloc(sizeof(unsigned int) * (n + 1));
  for (int i = 0; i <= n; ++i) {
    mem01[i] = -1; // 子问题中不会出现的状态作为记忆化搜索的初始值
  }
  clock_t start = clock();
  int x = fib02(n);
  printf("%d\n", x);
  clock_t end = clock();
  printf("cost time: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
  free(mem01);
}

// DP table
unsigned int fib03(unsigned int n) {
  unsigned int res;
  unsigned int *mem = (unsigned int *)malloc(sizeof(unsigned int) * (n + 1));
  mem[0] = 0;
  mem[1] = 1;
  for (int i = 2; i <= n; ++i) {
    mem[i] = mem[i - 1] + mem[i - 2];
  }
  res = mem[n];
  free(mem);
  return res;
}

void test03() {
  int n = 50;
  clock_t start = clock();
  int x = fib03(n);
  printf("%d\n", x);
  clock_t end = clock();
  printf("cost time: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
  free(mem01);
}

int main(int argc, char *argv[]) {
  test01();
  test02();
  test03();
  return EXIT_SUCCESS;
}
