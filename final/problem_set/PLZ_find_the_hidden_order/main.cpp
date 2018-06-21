#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testcase;
	cin >> testcase;
	string String;
	while(testcase--)
	{
		int len[10005] = {0};
		len[0] = 1;
		int Max = 1, lengthened = 0;
		cin >> String;
		for(int i = 1; i < String.length(); i++)
		{
			lengthened = 0;
			for(int j = 0; j < i; j++)
			{
				if((String[i] > String[j]) && ((len[j] + 1) > len[i]))
				{
					len[i] = len[j] + 1;
					lengthened = 1;
				}
				//cout << String[i] << ":len[i]=" << len[i] << "\n";
				if(!lengthened)len[i] = 1;
				if(len[i] > Max)Max = len[i];
			}
		}
		cout << Max << "\n";
	}
	return 0;
}
