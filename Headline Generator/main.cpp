#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
void insert();
void update();
void query();
unordered_map<int, long long> value;
int max_id;
long long max_value = LLONG_MIN;
long long insert_time = 0, k;
unordered_map<int, int> priority;

//main
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, flag;
	cin >> N >> k;
	while(N--){
		cin >> flag;
		switch(flag){
			case 1:
				insert();
				break;
			case 2:
				update();
				break;
			case 3:
				query();
				break;
		}
	}
	return 0;
}

//functions
void insert(){
	int id;
	long long new_value;
	cin >> id >> new_value;
	insert_time++;
	value[id] = new_value + k * insert_time;
	priority[id] = insert_time;
	if(value[id] > max_value || (value[id] == max_value && priority[id] > priority[max_id])){
		max_id = id; 
		max_value = value[id]; 
	}
}
void update(){
	long long adder;
	int id, n;
	cin >> adder >> n;
	while(n--){
		cin >> id;
		value[id] += adder;
		if(value[id] > max_value || (value[id] == max_value && priority[id] > priority[max_id])){
			max_id = id; 
			max_value = value[id]; 
		}
	}
}
void query(){
	cout << "id: " << max_id << ", value: " << (max_value - insert_time * k) << "\n";
}
