#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#include <bits/stdc++.h>
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


class traversal {

public:
	bool inOrderTraversal(const vector<Node>& tree, int location, int min, int max) {
		if (location == -1) {
			return true;
		}
		int newMax = tree[location].key;

		bool result = inOrderTraversal(tree, tree[location].left, min, newMax);
		if (!result) {
			return false;
		}
		if (tree[location].key > max) {
			return false;
		}
				
		if (tree[location].key < min) {
			return false;
		}

		int newMin = tree[location].key;

		result = inOrderTraversal(tree, tree[location].right, newMin, max);
		if (!result) {
			return false;
		}
		return result;
	}

};

bool IsBinarySearchTree(const vector<Node>& tree) {
	traversal inOrder;
	bool results;
	results = inOrder.inOrderTraversal(tree, 0, INT_MIN, INT_MAX);
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
	}
	else {
		cout << "INCORRECT" << endl;
	}
	return 0;
}
int main(int argc, char **argv)
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
				//std::cerr << "setrlimit returned result = " << result << std::endl;
			}
		}
	}
#endif

	return main_with_large_stack_space();
}
