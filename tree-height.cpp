#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int findTreeHeight(Node* root) {
    int maxHeight = 1;
    std::queue<Node *> nodeQ;
    nodeQ.push(root);
    int height = 1;

    while (!nodeQ.empty()) {
        maxHeight = std::max(height, maxHeight);
        Node* latestNode = nodeQ.front();
        nodeQ.pop();
        if (latestNode->children.empty()) {
            // Nada
        } else {
            for (auto x = latestNode->children.begin(); x < latestNode->children.end(); x++) {
                nodeQ.push(*x);
            }
            height++;
        }
    }
    return maxHeight;
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;
  std::vector<Node> nodes;
  nodes.resize(n);
  int rootLocation = 0;
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index == -1) {
        rootLocation = child_index;
    } else if (parent_index >= 0) {
      nodes[child_index].setParent(&nodes[parent_index]);
  }
  nodes[child_index].key = child_index;
  }
    int maxHeight = findTreeHeight(&nodes[rootLocation]);
  // Replace this code with a faster implementation
//  int maxHeight = 0;
//  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
//    int height = 0;
//    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
//      height++;
//    maxHeight = std::max(maxHeight, height);
//  }
  std::cout << maxHeight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
