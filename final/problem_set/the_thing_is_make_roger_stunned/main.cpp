#include<iostream>
#include<stack>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testcase, n, sample;
	cin >> testcase;
	while(testcase--)
	{
		int current = 1;
		bool success = true;
		stack<int> stick;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> sample;
			if(!success)continue;
			while(current <= n + 1)
			{				
				if(stick.size() == 0 || stick.top() < sample) stick.push(current++);
				else if(stick.size() != 0 && stick.top() == sample){stick.pop(); break;}
				else {success = false; break;}
			}
		}
		//cout << "n " << n << "current " << current << "\n";
		cout << "Y " << (success ? 1 : 2) << "\n";
	}
	return 0;
}
