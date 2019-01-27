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
	long root;

public:
	bool inOrderTraversal(const vector<Node>& tree, long location) {
		if (location == -1) {
			return true;
		}
		answerResults.push_back(tree[location].key);
		long leftLocation = tree[location].left;
		//cout << "Left location is " << leftLocation << endl;
		//cout << "Key is " << tree[location].key << endl;
		if (leftLocation != -1) {
			//cout << "Key in left location is " << tree[leftLocation].key << endl;
			if ((tree[location].key < 0) && (tree[leftLocation].key < 0)) {
				if (tree[location].key >= tree[leftLocation].key) {
					//cout << "I break in the wrong location 0" << endl;
					return false;
				}
			}
			if (tree[location].key <= tree[leftLocation].key) {
				//cout << "Tree key is " << tree[location].key << " and left location is " << tree[leftLocation].key;
				//cout << "i break in wrong location 1" << endl;
				return false;
			}
			if (tree[tree[leftLocation].right].key > tree[0].key) {
				//cout << "I'm guessing I broke here" << endl;
				return false;
			}
			//if (answerResults.size() > 0) {
			//	if (tree[leftLocation].key >= answerResults.back()) {
			//		cout << "i break in wrong location 2" << endl;
			//		cout << "Tree key is " << tree[leftLocation].key << " and answer resutls are " << answerResults.back();
			//		return false;
			//	}
			//}
		};
		//inOrderTraversal(tree, tree[location].left);
		//cout << "Answer results are " << answerResults.back() << endl;
		//cout << "Back of answerResults is " << answerResults.back() << endl;
		//cout << "Right location " << tree[location].right << endl;
		//inOrderTraversal(tree, tree[location].right);
		long rightLocation = tree[location].right;
		if (rightLocation != -1) {
			if (tree[location].key > tree[rightLocation].key) {
				//cout << "i break in wrong location 3" << endl;
				return false;
			}
			//if (tree[location].key < answerResults.back()) {
			//	cout << "i break in wrong location 4" << endl;
			//	//cout << "I really shouldn't be here either" << endl;
			//	cout << "Back of answerResults is " << answerResults.back() << endl;
			//	cout << "Key in breaking point is " << tree[location].key << endl;
			//	//cout << "Do I even make it here 3" << endl;
			//	return false;
			//}
			if (tree[rightLocation].left != -1) {
				if (tree[tree[rightLocation].left].key <= tree[0].key) {
					//cout << "I break in wrong location 5" << endl;
					return false;
				}
			}
		}
		return inOrderTraversal(tree, tree[location].left) and inOrderTraversal(tree, tree[location].right);
		//if (answerResults.back()) {
		//	if (tree[rightLocation].key < answerResults.back()) {
		//		return false;
		//	}
		//}
	}

};

bool IsBinarySearchTree(const vector<Node>& tree) {
	traversal inOrder;
	bool results;
	long min = tree[0].key;
	long max = tree[0].key;
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
				std::cerr << "setrlimit returned result = " << result << std::endl;
			}
		}
	}
#endif

	return main_with_large_stack_space();
}
