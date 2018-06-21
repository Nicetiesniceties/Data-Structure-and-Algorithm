#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int maximum[N][N], sum = 0;
	for(int i = 0 ; i < N; i++)
	{
		cin >> maximum[i][i];
		sum += maximum[i][i];
	}
	for(int l = 0; l < N; l++)
		for(int i = 0, j = l; j < N; j++, i++)
		{
			if(j == i + 1)
			{
				maximum[i][j] = max(maximum[i][i], maximum[j][j]);
				continue;
			}
			if(i != j)
				maximum[i][j] = max(maximum[i][i] + min(maximum[i + 2][j], maximum[i + 1][j - 1]), maximum[j][j] + min(maximum[i][j - 2], maximum[i + 1][j - 1]));
		}
	if(sum - maximum[0][N - 1] <= maximum[0][N - 1])cout << "Y\n";
	else cout << "N\n";
	cout << abs(2 * maximum[0][N - 1] - sum);
	return 0;
}
