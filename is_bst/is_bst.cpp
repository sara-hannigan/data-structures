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

vector<int> inOrderTraversal(const vector <int>&results, const vector<Node>& tree, int location) {
	vector<int> answerResults = results;
	if (location == -1) {
		//cout << "Do I make it here before I break";
		return answerResults;
	}
	//cout << "Left location " << tree[location].left;
	vector<int> leftResults = inOrderTraversal(results, tree, tree[location].left);
	answerResults.insert(answerResults.end(), leftResults.begin(), leftResults.end());
	//cout << "Do I even make it here " << endl;
	answerResults.push_back(tree[location].key);
	vector<int> rightResults = inOrderTraversal(results, tree, tree[location].right);
	answerResults.insert(answerResults.end(), rightResults.begin(), rightResults.end());
}

bool IsBinarySearchTree(const vector<Node>& tree) {
	vector<int> results;
	//cout << "Do I make it here \n";
	results = inOrderTraversal(results, tree, 0);
	for (int i = 0; i < results.size(); ++i) {
		//cout << results[i] << endl;
		if (i + 1 < results.size()) {
			if (results[i] > results[i + 1]) {
				//cout << "smaller result " << results[i] << endl;
				//cout << "larger result " << results[i + 1] << endl;
				return false;
			}
		}
	}
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
