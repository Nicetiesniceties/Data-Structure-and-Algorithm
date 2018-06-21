#include<iostream>
#include<queue>
using namespace std;
int Distance[100];
bool IsHole[100];
int Queue[100]; 
int name_to_index(string name);
int bfs(void);
int tens[8] = {1, -1, 2, -2, 1, -1, 2, -2};
int ones[8] = {2, -2, 1, -1, -2, 2, -1, 1};
int num_of_hole, start, destination, testcase;
string name, name_of_start, name_of_destination;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> num_of_hole;
	while(num_of_hole--)
	{
		cin >> name;
		IsHole[name_to_index(name)] = 1;
	}
	cin >> testcase;
	while(testcase--)
	{
		cin >> name_of_start >> name_of_destination;
		start = name_to_index(name_of_start);
		destination = name_to_index(name_of_destination);
		cout << "Going from " << name_of_start << " to " << name_of_destination << " needs " << bfs() << " moves.\n";
	}
	return 0;
}
int name_to_index(string name)
{
	return (name[0] - 'a') * 10 + (name[1] - '0');	
}
int bfs(void)
{
	//initialization
	Queue[1] = start;
	Distance[start] = 0;
	int head = 1, tail = 2; 
	int visited[100] = {0};
	//enqueue
	while(head != tail)
	{
		//cout << "head" << Queue[head] << "\n";
		for(int i = 0 ; i < 8; i++)
		{
			if((Queue[head] / 10 + tens[i] >= 0)  && (Queue[head] / 10 + tens[i] < 9)
				&& (Queue[head] % 10 + ones[i] >= 0)  && (Queue[head] % 10 + ones[i] < 9))
			{
				int New = Queue[head] + 10 * tens[i] + ones[i]; 
				if(IsHole[New] || visited[New]) continue;
				Queue[tail++] = New;
				visited[New] = 1;
				cout << New << "\n";
				if(New == destination)return Distance[Queue[head]] + 1;
				Distance[New] = Distance[Queue[head]] + 1;
			}
		}
		head++;
		cout << endl;
	}
	return -1;
}
