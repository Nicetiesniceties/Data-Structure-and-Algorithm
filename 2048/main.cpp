#include<cstdlib>
#include<iostream>
#include<bitset>
#include<cmath>
#include<vector>
using namespace std;
unsigned long long nextMap(unsigned long long map, int action);
void dfs(unsigned long long map, int action, vector<int> *path);
bool won(unsigned long long map);
void PrintMap(unsigned long long map);
void PrintPath(vector<int> path);
unsigned long long BitMap(int VecMap[16]);
void PrintError(void);
void PrintWin(unsigned long long map, vector<int> path);

int PowerTable[] = {0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
bool HaveWon = false;

//main
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> path;
	int N;
	cin >> N;
	while(N--){
		int VecMap[16];
		HaveWon = false;
		for(int i = 0; i < 16; i++)cin >> VecMap[i];
		unsigned long long map = BitMap(VecMap);
		//PrintMap(map);
		for(int act = 0; act < 4; act++)if(HaveWon == false)dfs(map, act, &path);
		if(HaveWon == false)PrintError();
		path.clear();
	}
	return 0;
}

//functions
void dfs(unsigned long long cur, int action, vector<int> *path)
{
	unsigned long long newMap = nextMap(cur, action);	
	if(newMap == cur)return;
	(*path).push_back(action);
	if(won(newMap) == true){
		PrintWin(newMap, *path);
		HaveWon = true;
		return;
	}
	for(int act = 0; act < 4; act++)if(HaveWon == false)dfs(newMap, act, path);
	(*path).pop_back();
}
bool won(unsigned long long map){
    for(int i = 0; i < 16; map = map >> 4ULL, i++)
        if(map % 16 == 11)return true;
    return false;
}
void PrintMap(unsigned long long map){
	for(int i = 0; i < 16; map = map >> 4ULL, i++)
		cout << PowerTable[map % 16] << ((i % 4 == 3) ? "\n" : " ");  
}
void PrintPath(vector<int> path){
	for(int i = 0; i < path.size() - 1; i++)cout<< path[i] << " ";
	cout << path[path.size() - 1] << "\n"; 
}
unsigned long long BitMap(int VecMap[16]){
	unsigned long long map = 0;
	for(int i = 15; i >= 0; i--){
		map *= 16;
		if(VecMap[i]){map += (unsigned long long)log2(VecMap[i]);}
		}
	return map;
}
void PrintError(void){
	cout<<"Action:\n-1\nFinal:\n";
	for(int i = 0; i < 16; i++)cout << "-1" << ((i % 4 == 3) ? "\n" : " ");
}
void PrintWin(unsigned long long map, vector<int> path){
	cout<<"Action:\n";
	PrintPath(path);
	cout<<"Final:\n";
	PrintMap(map);
}
