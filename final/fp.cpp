#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#define MaxString 10000
using namespace std;

int Strategy(vector<int> num,int numstart,int numend,vector<int> op,int ans){
	int sum = 0;
	if (numstart == numend)
		return (ans == num.at(numstart));
	if (numstart == numend - 1){
		//cout << "Step 1" << endl;
		switch(op.at(numstart)){
			case 1:
				return ((num.at(numstart) && num.at(numend)) == ans);
				break;
			case 2:
				return ((num.at(numstart) || num.at(numend)) == ans);
				break;
			case 3:
				if ((num.at(numstart) == 0 && num.at(numend) == 1) || (num.at(numstart) == 1 && num.at(numend) == 0))
					return (1 == ans);
				else return (0 == ans);
			default:
				cout << "Last,ERROR!" << endl;
		}
	}
	//cout << "step 2" << endl;
	for (int i = numstart; i < numend; i++){
		int a = Strategy(num,numstart,i,op,1);
		int b = Strategy(num,numstart,i,op,0);
		int c = Strategy(num,i + 1,numend,op,1);
		int d = Strategy(num,i + 1,numend,op,0);
		printf ("The ans of %d in %d %d,when ans = %d is %d,%d,%d,%d\n",i,numstart,numend,ans,a,b,c,d);
		if (ans == 1){
			switch(op.at(i)){
				case 1:
					sum += a * c;
					cout << "1,sum = " << sum << endl;
					break;
				case 2:
					sum += a * c;
					sum += b * c;
					sum += a * d;
					cout << "2,sum = " << sum << endl;
					break;
				case 3:
					sum += a * d;
					sum += b * c;
					cout << "3,sum = " << sum << endl;
					break;
				default:
					cout << "True,ERROR!" << endl;
			}
		}
		if(ans == 0){
			switch(op.at(i)){
				case 1:
					sum += a * d + b * c + b * d;
					cout << "1,sum = " << sum << endl;
					break;
				case 2:
					sum += b * d;
					cout << "2,sum = " << sum << endl;
					break;
				case 3:
					sum += a * c + b * d;
					cout << "3.sum = " << sum << endl;
					break;
				default:
					cout << "False,ERROR!" << op.at(i) << endl;
			}
		}
		//else  cout << "ans,ERROR!" << endl;
	}
	return sum;
}

int main(){
	int N;
	cin >> N;
	cin.get();
	for (int i = 0; i < N; i ++){
		char s[MaxString];
		cin.getline(s,MaxString);
		//cout << s << endl;
		vector <int>num;
		vector <int>op;
		vector <int>:: iterator vecpt;
		num.reserve(1000);
		op.reserve(1000);
		for (int j = 0; s[j] != '\0'; j++){
			if (s[j] == 'e'){
				//cout << "a" << endl;
				if (s[j - 3] == 't'){
					//cout << "a" << endl;
					num.push_back(1);
				}
				else if (s[j - 4] == 'f'){
					//cout << "b" << endl;
					num.push_back(0);
				}
			}
			if (s[j] == 'd' && s[j - 2] == 'a'){
				op.push_back(1);
			}
			if (s[j] == 'r'){
				if (s[j - 2] == 'x'){
					op.push_back(3);
				}
				else if (s[j - 1] == 'o'){
					op.push_back(2);
				}
			}	
		}
		int ans;
		ans = Strategy(num,0,num.size()-1,op,1);
		cout << "Answer = " << ans << endl;
		//cout << "size of num = " << num.size() << endl;
		//for (vecpt = num.begin(); vecpt != num.end(); vecpt++)
		//	cout << *vecpt << " ";
		//cout << endl;
		//for (vecpt = op.begin(); vecpt != op.end(); vecpt++)
		//	cout << *vecpt << " ";
		//cout << endl;
		num.clear();
		op.clear();
	}
	return 0;
}
