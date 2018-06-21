#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> stack;
struct node
{
	bool is_push;
	struct node *pre;
	struct node *pop;
	struct node *push; 
};
typedef struct node Node;

void print(Node * external, int cur);
Node *newnode(Node *pre, bool is_push);
void permutation(Node *head, int size_of_stack, int count);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	Node *tree = newnode(NULL, false);
	permutation(tree, 1, 0);
	return 0;	
}
void print(Node *external, int cur)
{
	if(external == NULL)
	{
		cout << " \n";
		return;
	}
	else if(external->is_push)
	{	
		stack.push_back(cur);
		print(external->pre, cur + 1);
	}
	else if(!(external->is_push))
	{
		cout << stack[stack.size() - 1] << " ";
		stack.pop_back();
		print(external->pre, cur);
	}	
}
Node * newnode(Node *Pre, bool Is_push)
{
	Node *New = (Node *)malloc(sizeof(Node));
	New->is_push = Is_push;
	New->pre = Pre;
	New->pop = New->push = NULL;
	return New;
}
void permutation(Node *head, int number_of_pop, int number_of_push)
{
	if((number_of_push == N) && (number_of_pop == N))
	{
		print(head, 1);
		return;
	}
	if(number_of_pop < N)
	{
		head->pop = newnode(head, false);
		permutation(head->pop, number_of_pop + 1, number_of_push);
	}
	if(number_of_pop > number_of_push)
	{
		head->push = newnode(head, true);
		permutation(head->push, number_of_pop, number_of_push + 1);
	}
}
