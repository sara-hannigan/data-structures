#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;
using std::endl;

class TreeOrders {
	int n;
	vector <int> key;
	vector <int> left;
	vector <int> right;

public:
	void read() {
		cin >> n;
		key.resize(n);
		left.resize(n);
		right.resize(n);

		for (int i = 0; i < n; i++) {
			cin >> key[i] >> left[i] >> right[i];
		}
	}

	void postOrderRecursion(int tree) {
		if (tree == -1) {
			return;
		}
		postOrderRecursion(left[tree]);
		postOrderRecursion(right[tree]);
		cout << key[tree] << " ";

		//Don't really get how to do this with how they have it set up???????
	}

	void inOrderRecursion(int tree) {
		if (tree == -1) {
			return;
		}
		inOrderRecursion(left[tree]);
		cout << key[tree] << " ";
		inOrderRecursion(right[tree]);

		//Don't really get how to do this with how they have it set up???????
	}

	void preOrderRecursion(int tree) {
		if (tree == -1) {
			return;
		}
		cout << key[tree] << " ";
		//cout << "left tree index is " << left[tree] << endl;
		//cout << "Left tree key index is " << key[left[tree]] << endl;
		preOrderRecursion(left[tree]);
		preOrderRecursion(right[tree]);

		//Don't really get how to do this with how they have it set up???????
	}


	void in_order() {
		// Finish the implementation
		// You may need to add a new recursive method to do that
		//EX On traverse
		// Key 0 has a value of 4. Its children are key1 + key2. Key 1 left has key3 as a child, key1 right has key4 as a child
		inOrderRecursion(0);
	}

	void pre_order() {
		// Finish the implementation
		// You may need to add a new recursive method to do that
		preOrderRecursion(0);
	}

	void post_order() {
		// Finish the implementation
		// You may need to add a new recursive method to do that
		postOrderRecursion(0);
	}
};

void print(vector <int> a) {
	for (size_t i = 0; i < a.size(); i++) {
		if (i > 0) {
			cout << ' ';
		}
		cout << a[i];
	}
	cout << '\n';
}

int main_with_large_stack_space() {
	ios_base::sync_with_stdio(0);
	TreeOrders t;
	t.read();
	t.in_order();
	cout << '\n';
	t.pre_order();
	cout << '\n';
	t.post_order();
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

