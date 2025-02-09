/**
* 다시 풀기
* 트리 순회 순서 변경: https://www.algospot.com/judge/problem/read/TRAVERSAL
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	const int N = preorder.size();
	if (preorder.empty()) return;

	const int root = preorder[0];
	int L = -1;
	for (int i = 0; i < inorder.size(); i++) {
		if (root == inorder[i]) {
			L = i;
			break;
		}
	}
	//const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));	// left
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));	// right
	cout << root << " ";

}

int main() {
	int C;
	cin >> C;
	while (C-- > 0) {
		int n;
		cin >> n;
		vector<int> preorder, inorder;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			preorder.push_back(t);
		}
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			inorder.push_back(t);
		}
		printPostOrder(preorder, inorder);
	}
	return 0;
}