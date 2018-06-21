#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dispatch(queue<int> input,stack<int> current,vector<int> output)
{
	//判断输入队列中是否还有火车
	bool hasInput=true;

	//判断火车站里是否还有火车
	bool hasCurrent=true;

	if(input.size()==0)
		hasInput=false;

	if(current.size()==0)
		hasCurrent=false;

	//如果没有输入并且当前火车站中也有没火车
	if(!hasInput&&!hasCurrent)
	{
		//打印输出
		vector<int>::iterator it=output.begin();
		for (;it!=output.end()-1;it++)
		{
			cout<<*it<<" ";
		}
		cout<<*it;
		cout<<" \n";
		return ;	
	}
//火车站中有火车要入栈
	if(hasInput)
	{
		queue<int> inputTmp=input;
		stack<int> currentTmp=current;
		currentTmp.push(inputTmp.front());
		inputTmp.pop();
		dispatch(inputTmp,currentTmp,output);
	}

	//火车站中有火车要出栈
	if(hasCurrent)
	{
		stack<int> currentTmp=current;
		vector<int> outputTmp=output;
		outputTmp.push_back(currentTmp.top());
		currentTmp.pop();
		dispatch(input,currentTmp,outputTmp);

	}

	}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int nums=0;
	//处理输入
	queue<int> input;//存放输入火车的队列
	stack<int> current;//存在火车站中火车的栈
	vector<int> output;//输出火车的序列
	//从标准输入中读取入队的火车标号
	
	cin >> nums;
	for(int i=1;i<=nums;i++)
	{
		int tmp;
		input.push(i);
	}
	//调用分配函数
	dispatch(input,current,output);
	getchar();
	return 0;
}
