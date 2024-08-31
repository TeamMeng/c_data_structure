#include "RBTree.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  KeyType data[] = {55, 49, 65, 69, 75, 57, 63, 56};
  RBTree *tree = createRBTree();
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
    insertRBTree(tree, data[i]);
  }
  printRBTree(tree->root, tree->root->key, 0);
  deleteRBTree(tree, 49);
  printRBTree(tree->root, tree->root->key, 0);
  releaseRBTree(tree);
  return EXIT_SUCCESS;
}
