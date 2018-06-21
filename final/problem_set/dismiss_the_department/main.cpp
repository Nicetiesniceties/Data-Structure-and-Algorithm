#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool myfunction (int i,int j) { return (i<j); }
unordered_map<int, vector<int> > company;
vector<int> ID;
vector<int>output;
void kill(int id)
{
	output.push_back(id);
	for(int i = 0; i < company[id].size(); i++)
		kill(company[id][i]);
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int num, temp;
	cin >> num;
	for(int i = 0; i < num; i++)
	{	
		cin >> temp;
		ID.push_back(temp);
	}
	for(int i = 0; i < num; i++)
	{
		cin >> temp;
		company[temp].push_back(ID[i]);
	}
	cin >>temp;
	kill(temp);
	sort (output.begin(), output.end(), myfunction);
	for(int i = 0; i < output.size(); i++)
	{
		cout << output[i];
		if(i != output.size() - 1)cout << " ";
	}
	return 0;
}
