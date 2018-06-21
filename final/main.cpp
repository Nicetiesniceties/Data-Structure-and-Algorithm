#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int count(vector<string> symb, vector<string> oper, int n)
{
	int False[n][n], True[n][n];
    for (int i = 0; i < n; i++)
    {
        //cout << symb[i] << " ";
		False[i][i] = (symb[i].compare("false")) ? 0 : 1;
        True[i][i] = (symb[i].compare("true")) ? 0 : 1;
    }
    for (int gap = 1; gap < n; gap++)
    {
        for (int i=0, j=gap; j < n; i++, j++)
        {
            True[i][j] = False[i][j] = 0;
            for (int g = 0; g < gap; g++)
            {
                int k = i + g;
                int total_front = True[i][k] + False[i][k];
                int total_back = True[k + 1][j] + False[k + 1][j];
                if (!oper[k].compare("and"))
                {
                    True[i][j] += True[i][k] * True[k+1][j];
                    False[i][j] += (total_front * total_back - True[i][k] * True[k+1][j]);
                }
                if (!oper[k].compare("or"))
                {
                    False[i][j] += False[i][k] * False[k + 1][j];
                    True[i][j] += (total_front * total_back - False[i][k] * False[k + 1][j]);
                }
                if (!oper[k].compare("xor"))
                {
                    True[i][j] += False[i][k] * True[k + 1][j] + True[i][k] * False[k + 1][j];
                    False[i][j] += True[i][k] * True[k + 1][j] + False[i][k] * False[k + 1][j];
                }
            }
        }
    }
    return True[0][n - 1];
}
int main()
{
    /*char symbols[] = "FTTFT";
    char operators[] = "|||^";
    int n = strlen(symbols);*/
	int N, W;
	cin >> N;
	while(N--)
	{
		cin >> W;
		string temp;
		vector<string> symbols, operators;
		while(W--)
		{
			cin >> temp;
			if(!temp.compare("true") || !temp.compare("false")) symbols.push_back(temp);
			else operators.push_back(temp);
		}
		cout << count(symbols, operators, symbols.size()) << "\n";
    	symbols.clear();
		operators.clear();
	}
	return 0;
}
