#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
void insert(vector<unordered_map<int, unsigned long long>> heap, int k, unordered_map<int, unsigned long long> value);
void update(vector<unordered_map<int, unsigned long long>> heap, unordered_map<int, unsigned long long> value);
void query(vector<unordered_map<int, unsigned long long>> heap, unordered_map<int, unsigned long long> value); 

//main
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unordered_map<int, unsigned long long> value;
	vector<int> heap;
	make_heap (heap.begin(), heap.end());
	int N, k, flag;
	cin >> N >> k;
	while(N--){
		cin >> flag;
		switch(flag){
			case 1:
				insert(heap, k);
				break;
			case 2:
				update(heap);
			case 3:
				query(heap);
		}
	}
	return 0;
}

//functions
void insert(vector<unordered_map<int, int>> heap, int k, unordered_map<int, unsigned long long> value){
	int id;
	cin >> id >> map[id];
	for(unordered_map<int, unsigned long long> iterator i = value.begin(); i != value.end(); ++i)(i->second) -= k;

}
void update(vector<unordered_map<int, unsigned long long>> heap, unordered_map<int, unsigned long long> value);
void query(vector<unordered_map<int, unsigned long long>> heap, unordered_map<int, unsigned long long> value); 

