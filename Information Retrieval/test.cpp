#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	fstream file;
	file.open("input");
	char ch;
	while(file.get(ch)){
		cout << ch;
		}
	file.close();
	return 0;
	}


