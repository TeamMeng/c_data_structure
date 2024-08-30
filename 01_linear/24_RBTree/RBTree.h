#ifndef RB_TREE_H
#define RB_TREE_H

enum RBColor { RED, BLACK };

typedef int KeyType;

// 红黑树的节点结构
typedef struct RBNode {
  char color;
  KeyType key;
  struct RBNode *parent;
  struct RBNode *left;
  struct RBNode *right;
} RBNode;

// 定义红黑树的结构
typedef struct {
  RBNode *root;
  int count;
} RBTree;

RBTree *createRBTree();

// 向红黑树插入值
void insertRBTree(RBTree *tree, KeyType key);
// 显示红黑树
void printRBTree(RBNode *node, KeyType key, int dir);
// 释放红黑树
void releaseRBTree(RBTree *tree);
#endif // !RB_TREE_H
