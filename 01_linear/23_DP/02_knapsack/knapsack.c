#include <stdio.h>
#include <stdlib.h>

static int w_goods[] = {1, 2, 3};
static int val_goods[] = {6, 10, 12};
static int bag_capacity = 5;

static int max(int a, int b) { return a > b ? a : b; }

// 用[0..idx]的物品, 填充容积为C的背包的最大值
static int bestValue(int idx, int c) {
  if (idx < 0 || c <= 0) {
    return 0;
  }
  // 只考虑[0..idx - 1]这么多物品来填充容积为c的背包
  int res = bestValue(idx - 1, c);
  // 考虑idx物品放入背包
  if (c >= w_goods[idx]) {
    res = max(res, val_goods[idx] + bestValue(idx - 1, c - w_goods[idx]));
  }
  return res;
}

int knapsack01() {
  return bestValue(sizeof(val_goods) / sizeof(val_goods[0]) - 1, bag_capacity);
}

static int bestValue02(int idx, int c, void *data) {
  int(*mem)[bag_capacity + 1] = (int(*)[bag_capacity + 1]) data;
  if (idx < 0 || c <= 0) {
    return 0;
  }
  int res = bestValue02(idx - 1, c, mem);
  if (c >= w_goods[idx]) {
    res =
        max(res, val_goods[idx] + bestValue02(idx - 1, c - w_goods[idx], mem));
  }
  mem[idx][c] = res;
  return res;
}

int knapsack02() {
  int n = sizeof(val_goods) / sizeof(val_goods[0]);
  int(*mem)[bag_capacity + 1] =
      (int(*)[bag_capacity + 1]) malloc(sizeof(int) * n * (bag_capacity + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= bag_capacity + 1; ++j) {
      mem[i][j] = -1;
    }
  }
  int res =
      bestValue02(sizeof(val_goods) / sizeof(val_goods[0]), bag_capacity, mem);
  free(mem);
  return res;
}

int knapsackDP(int n, int c) {
  int(*dp)[c + 1] = (int(*)[c + 1]) malloc(sizeof(int) * n * (c + 1));
  // 初始化第0行
  for (int i = 0; i <= c; ++i) {
    dp[0][i] = (i >= w_goods[0]) ? w_goods[0] : 0;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= c; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j >= w_goods[i]) {
        dp[i][j] = max(dp[i][j], val_goods[i] + dp[i - 1][j - w_goods[i]]);
      }
    }
  }
  return dp[n][c];
}

int main(int argc, char *argv[]) {
  int res = knapsack01();
  printf("%d\n", res);
  res = knapsack02();
  printf("%d\n", res);
  res = knapsackDP(sizeof(w_goods) / sizeof(w_goods[0]), bag_capacity);
  printf("%d\n", res);
  return EXIT_SUCCESS;
}
