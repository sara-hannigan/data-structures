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
  long long key;
  long long left;
  long long right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, long long left_, long long right_) : key(key_), left(left_), right(right_) {}
};


class traversal {
private:
	vector<Node> answerResults;
	long long root;

public:
	bool inOrderTraversal(const vector<Node>& tree, long long location) {
		bool results = true;
		if (location == -1) {
			cout << "When do I make it here?" << endl;
			return true;
		}
		results = inOrderTraversal(tree, tree[location].left);
		cout << "I just set left results to " << results << endl;
		if (results == false) {
			cout << "I break here weirdly " << results << endl;
			return false;
	 	}
		long long leftLocation = tree[location].left;
		long long rightLocation = tree[location].right;
		long long subLeftRightTree = tree[rightLocation].left;
		if (answerResults.size() > 0) {
			Node temp;
			temp = answerResults.back();
			if (tree[location].key < temp.key) {
				cout << "Am I making it here?" << endl;
				cout << tree[location].key << " " << temp.key << endl;
				return false;
			}
//			if (tree[location].key == temp.key) {;
//				if (leftLocation != -1) {
//					if (tree[leftLocation].key == tree[location].key) { 
//						return false;
//					}
//				}
//				if (rightLocation != -1) {
//					if (tree[rightLocation].key < tree[location].key) {;
//						return false;
//					}
//				}
//			}
//			} else if (subLeftRightTree != -1) {
//				cout << "I break here 1" << endl;
//				cout << "Tree key " << tree[location].key << endl;
//				cout << "right subtree left key value " << tree[subLeftRightTree].key << endl;
//				if ((long long)tree[location].key == (long long)tree[subLeftRightTree].key) {
//					return false;
//				}
//			}
		}
		answerResults.push_back(tree[location]);
		Node temp = answerResults.back();
		cout << "Answers back is " << temp.key << endl;
		results = inOrderTraversal(tree, tree[location].right);
		cout << "I just set results right to " << results << endl;
		if (!results) {
			cout << "I break here weirdly 1 " << results << endl;
			return false;
		}
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
	long long nodes;
	cin >> nodes;
	if (nodes == 0) {
		cout << "CORRECT" << endl;
		return 0;
	}
	vector<Node> tree;
	for (long long i = 0; i < nodes; ++i) {
		long long key, left, right;
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
