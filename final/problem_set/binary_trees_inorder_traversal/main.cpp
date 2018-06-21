#include<iostream>
#include<vector>
using namespace std;
void inorder(vector<int> tree, int index);
int leftchild(int pre);
int rightchild(int pre);
int testcase, size_of_tree, num, n;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> testcase;
	while(testcase--)
	{
		cin >> size_of_tree;
		vector<int>tree;
		tree.push_back(-1);
		for(int i = 1; i <= size_of_tree; i++)
		{
			cin >> n;
			tree.push_back(n);
		}
		inorder(tree, 1);
		tree.clear();
		if(testcase)cout << "\n";
	}
}
int leftchild(int pre)
{
	return 2 * pre;
}
int rightchild(int pre)
{
	return 2 * pre + 1;
}
void inorder(vector<int> tree, int index)
{
		if(tree[index] == -1)return;
		if(leftchild(index) <= size_of_tree)
			inorder(tree, leftchild(index));
		cout << tree[index] << " ";
		if(rightchild(index) <= size_of_tree)
			inorder(tree, rightchild(index));
}
