#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(void)
{
	string s; 
	stringstream ss;
	int n;
	vector<string> output;
	string a;; 
	//cin >> n; 
	//getline(cin, s); 
	// 讀取換行  
	while(getline(cin, s)) 
	{
	ss.clear(); 
	ss.str(s); 
	//sum=0; 
	while (1) 
	{	 
		ss >> a;
		if ( ss.fail() ) break; 
		output.push_back(a); 
	}
	for(int i = 0; i < output.size(); i++)
	cout << output[i] << " ";
	output.clear();
	}
	return 0;
}
