#include<iostream>
using namespace std;
int N, S[1005][1005], M[1005][1005];
 /* UTILITY FUNCTIONS */
/* Function to get minimum of three values */
int Min(int a, int b, int c)
{
	int m = a;
	if (m > b) 
		m = b;
	if (m > c) 
    	m = c;
	return m;
}
int printMaxSubSquare(void)
{
	int i,j;
	/* Set first column of S[][]*/
	for(i = 0; i < N; i++)
    	S[i][0] = M[i][0];
  
	/* Set first row of S[][]*/    
	for(j = 0; j < N; j++)
    	S[0][j] = M[0][j];
      
	/* Construct other entries of S[][]*/
	for(i = 1; i < N; i++)
    	for(j = 1; j < N; j++)
      		if(M[i][j] == 1)S[i][j] = Min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
			else S[i][j] = 0;
	int Count = 0;
	for(i = 0; i < N; i++)
  	{	
		for(j = 0; j < N; j++)
		{
			Count += S[i][j];
			//cout << S[i][j] << " ";
		}
		//cout << endl;
	}
	return Count;
}
int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testcase;    
	char temp;
	cin >> testcase;
 	while(testcase--)
 	{
		cin >> N;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
			{
				cin >> temp;
				if(temp == '1')M[i][j] = 1;
				else M[i][j] = 0;
			}
		cout  << printMaxSubSquare() << "\n";
	}
	return 0;
}  
