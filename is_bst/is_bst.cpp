#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::ios_base;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool inOrderTraversal(const vector<Node>& tree, int location, int prevLocation) {
	if (location == -1) {
		//cout << "Do I make it here before I break";
		return true;
	}
	if (location == 0 && prevLocation == 0) {
		inOrderTraversal(tree, tree[location].left, location);
	}
	if (!inOrderTraversal(tree, tree[location].left, location)) {
		return false;
	}
	if (tree[prevLocation].key != -1 && tree[location].key <= tree[prevLocation].key) {
		return false;
	}

	return inOrderTraversal(tree, tree[location].right, location);
	//cout << "Left location " << tree[location].left;
	/*int leftIndex = tree[location].left;
	if ((tree[leftIndex].key != -1) && (tree[location].key < tree[leftIndex].key)) {
		return false;
	}
	int rightIndex = tree[location].right;
	if ((tree[rightIndex].key != -1) && (tree[location].key > tree[rightIndex].key)) {
		return false;
	}
	
	return inOrderTraversal(tree, tree[location].left) and inOrderTraversal(tree, tree[location].right);*/
}

bool IsBinarySearchTree(const vector<Node>& tree) {
	bool results;
	//cout << "Do I make it here \n";
	results = inOrderTraversal(tree, 0, 0);
	return results;
}

int main_with_large_stack_space() {
	ios_base::sync_with_stdio(0);
  int nodes;
  cin >> nodes;
  if (nodes == 0) {
	  cout << "CORRECT" << endl;
	  return 0;
  }
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}

int main(int argc, char **argv) {
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

