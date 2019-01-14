#include <algorithm>
#include <iostream>
#include <vector>

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

bool inOrderTraversal(const vector<Node>& tree, int location, int preVal) {
	if (location == -1) {
		//cout << "Do I make it here before I break";
		return true;
	}
	if ((preVal != -1) && (preVal != 0) && (tree[location].key < preVal)) {
		return false;
	}
	int leftLocation = tree[location].left;
	//cout << "Left location " << tree[location].left;
	return inOrderTraversal(tree, tree[location].left, tree[location].key) and inOrderTraversal(tree, tree[location].right, tree[location].key);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
	//cout << "Do I make it here \n";
	bool results = inOrderTraversal(tree, 0, 0);
	return results;
	// Implement correct algorithm here
	  //Probably recursion, 
	  //set to return false any time the nodes are larger on the left or smaller on the right
	  //Check if left val smaller than current val, then recurse down
	  //Do opposite for right
	  //save a max and a min value?....is that necessary?
	  //I feel like left/right should just always be smaller or larger
	  //keep in mind equal conditions, node should be on the right
	  //OR consider an in-order traversal?
}

int main() {
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
