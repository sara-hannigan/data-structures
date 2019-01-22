#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long key;
  long left;
  long right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long key_, long left_, long right_) : key(key_), left(left_), right(right_) {}
};
//
//int traversalHelper(const vector<Node>& tree, int location) {
//	if (location == -1) {
//		//cout << "Do I make it here before I break";
//		tree[location].key;
//	}
//	return inOrderTraversal(tree, tree[location].left) && inOrderTraversal(results, tree, tree[location].right);
//
//
//
//}

class traversal {
private:
	vector<long> answerResults;

public:
	bool inOrderTraversal(const vector<Node>& tree, long location) {
		if (location == -1) {
			return true;
		}
		long leftLocation = tree[location].left;
		//cout << "Left location is " << leftLocation << endl;
		//cout << "Key is " << tree[location].key << endl;
		if (leftLocation != -1) {
			//cout << "Key in left location is " << tree[leftLocation].key << endl;
			if (tree[location].key <= tree[leftLocation].key) {
				//cout << "left key is " << tree[leftLocation].key << endl;
				return false;
			}
			if ((tree[location].key < 0) && (tree[leftLocation].key < 0)) {
				if (tree[location].key >= tree[leftLocation].key) {
					return false;
				}
			}
		}
		//if (answerResults.size() > 0) {
		//	cout << "Back of answerResults is " << answerResults.back() << endl;
		//	if (tree[location].key > answerResults.back()) {
		//		cout << "Key in breaking point is " << tree[location].key << endl;
		//		return false;
		//	}

		//}
		answerResults.push_back(tree[location].key);
		//cout << "Back of answerResults is " << answerResults.back() << endl;
		inOrderTraversal(tree, tree[location].left);
		//cout << "Right location " << tree[location].right << endl;
		long rightLocation = tree[location].right;
		if (rightLocation !=-1) {
				if (tree[rightLocation].key < tree[location].key) {
					return false;
				}
		}
		if (tree[location].key < answerResults.back()) {
			//cout << "I really shouldn't be here either" << endl;
			//cout << "Back of answerResults is " << answerResults.back() << endl;
			//cout << "Key in breaking point is " << tree[location].key << endl;
			//cout << "Do I even make it here 3" << endl;
			return false;
		}
		inOrderTraversal(tree, tree[location].right);
		}

		//if (answerResults.back()) {
		//	if (tree[rightLocation].key < answerResults.back()) {
		//		cout << "Do I even make it here 4" << endl;
		//		return false;
		//	}
		//}

};

bool IsBinarySearchTree(const vector<Node>& tree) {
	traversal inOrder;
	bool results;
	results = inOrder.inOrderTraversal(tree, 0);
	return results;
	//for (int i = 0; i < results.size(); ++i) {
	//	//cout << results[i] << endl;
	//	if (i + 1 < results.size()) {
	//		if (results[i] > results[i + 1]) {
	//			//cout << "smaller result " << results[i] << endl;
	//			//cout << "larger result " << results[i + 1] << endl;
	//			return false;
	//		}
	//	}
  // Implement correct algorithm here
	//Probably recursion, 
	//set to return false any time the nodes are larger on the left or smaller on the right
	//Check if left val smaller than current val, then recurse down
	//Do opposite for right
	//save a max and a min value?....is that necessary?
	//I feel like left/right should just always be smaller or larger
	//keep in mind equal conditions, node should be on the right
	//OR consider an in-order traversal?
	return true;
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
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
