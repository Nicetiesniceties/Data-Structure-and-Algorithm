#include<iostream>
#include<vector>
using namespace std;
int N;
void dfs(vector<int> result, vector<int> stack, int cur)
{
	if(cur > N)
		for(int i = 0; i < N; i++)cout << result[i] << ((i == N - 1) ? "\n" : "");		
	else
	{	
		vector<int> temp_result;
		vector<int> temp_stack;
		for(int i = 0; i < result.size(); i++)
			temp_result.push_back(result[i]);
		for(int i = 0; i < stack.size(); i++)
			temp_stack.push_back(stack[i]);
		cout << 123 << "\n";
		temp_stack.push_back(cur);
		dfs(temp_result, temp_stack, cur + 1);//push
		if(temp_stack.size() > 1)
		{
			//pop
			temp_stack.pop_back();
			temp_result.push_back(temp_stack[temp_stack.size() - 1]);
			temp_stack.pop_back();
			dfs(temp_result, temp_stack, cur);
		}
		// temp_result.clear();
		// temp_stack.clear();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	vector<int> result, stack;
	dfs(result, stack, 1);
	return 0;	
}
