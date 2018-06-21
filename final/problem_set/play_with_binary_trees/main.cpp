#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int size_of_tree, temp;
vector<int> tree;

void print(int index);
void DFS(int index, int sum);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	tree.push_back(0);
	cin >> size_of_tree;
	size_of_tree = pow(2, size_of_tree + 1) - 1;
	for(int i = 0; i < size_of_tree; i++)
	{
		cin >> temp;
		tree.push_back(temp);
	}
	cin >> temp;
	DFS(1, tree[1]);
	return 0;
}
void print(int index)
{
	vector<int> temp_tree;
	while(index)
	{
		temp_tree.push_back(tree[index]);
		//cout << index;
		index /= 2;
	}
	vector<int> :: iterator j = temp_tree.begin();
	for(vector<int> :: iterator i = temp_tree.end() - 1;; --i)
	{
		if(i != j)cout << *i << " ";
		else
		{
			cout << *i << "\n";
			break;
		}
	}
}
void DFS(int index, int sum)
{
	if(temp == sum)print(index);
	if(2 * index <= size_of_tree)DFS(2 * index, sum + tree[2 * index]);
	if(2 * index + 1 <= size_of_tree)DFS(2 * index + 1, sum + tree[2 * index + 1]);
}
