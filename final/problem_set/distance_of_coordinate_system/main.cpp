#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string temp, numbers;
	int testcase, num;
	cin >> testcase;
	while(testcase--)
	{
		cin >> num;
		cin >> numbers;
		temp = numbers;
		for(int i = 0 ; i < num; i++)
		{
			next_permutation(numbers.begin(), numbers.end());
			if(numbers <= temp)
			{
				cout << "NOPE!!\n";
				break;
			}
			if(i == num - 1)
				cout << numbers << "\n";
		}
	}
	return 0;
}
