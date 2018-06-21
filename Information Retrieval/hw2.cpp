#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

using namespace std;
#define const 100

int main(){
	ifstream file1;
	ifstream file2;
	ifstream file3;
	ifstream file4;

	char a[const];
	char b[const];
	char c[const];
	char d[const];
	char e[const];
	char f[const];
	long long int num;
	map<string,vector<int> > :: iterator temp;
	map<string,vector<int> > twoone;
	map<string,vector<int> > twotwo;
	map<string,vector<int> > threeone;
	map<string,vector<int> > threetwo;
	map<string,vector<int> > threethree;
	map<string,vector<int> > fourone;
	map<string,vector<int> > fourtwo;
	map<string,vector<int> > fourthree;
	map<string,vector<int> > fourfour;
	map<string,vector<int> > fiveone;
	map<string,vector<int> > fivetwo;
	map<string,vector<int> > fivethree;
	map<string,vector<int> > fivefour;
	map<string,vector<int> > fivefive; 
	map<string,vector<int> > twofre;
	map<string,vector<int> > threefre;
	map<string,vector<int> > fourfre;
	map<string,vector<int> > fivefre;
	cout << sizeof(fiveone) << endl;
	file1.open("2gm.small.txt");
	file2.open("3gm.small.txt");
	file3.open("4gm.small.txt");
	file4.open("5gm.small.txt");
	int i = 1;




	while(file1.getline(a,sizeof(a),' ')){//read2
		twoone[a].push_back(i);
		file1.getline(b,sizeof(b),'\t');
		twotwo[b].push_back(i);
		file1.getline(c,sizeof(c),'\n');
		twofre[c].push_back(i);
		num = atol(c);


		int *pt;
		temp = twoone.find(a);
		cout << temp->second.back() << " " << temp->first;
		temp = twotwo.find(b);
		cout << " " << temp->first;
		cout << " " << num << endl;
		i++;
	}
	file1.close();

	cout << endl << endl;





	i = 1;
	while(file2.getline(a,sizeof(a),' ')){//read3
		threeone[a].push_back(i);
		file2.getline(b,sizeof(b),' ');
		threetwo[b].push_back(i);
		file2.getline(c,sizeof(c),'\t');
		threethree[c].push_back(i);
		file2.getline(d,sizeof(d),'\n');
		num = atol(d);
		threefre[d].push_back(i);

		temp = threeone.find(a);
		cout << temp->second.back() << " " << temp->first;
		temp = threetwo.find(b);
		cout << " " << temp->first;
		temp = threethree.find(c);
		cout << " " << temp->first;
		cout << " " << num << endl;
		i++;
	}
	file2.close();
	cout << endl << endl;




	i = 1;
	while(file3.getline(a,sizeof(a),' ')){//read4
		fourone[a].push_back(i);
		file3.getline(b,sizeof(b),' ');
		fourtwo[b].push_back(i);
		file3.getline(c,sizeof(c),' ');
		fourthree[c].push_back(i);
		file3.getline(d,sizeof(d),'\t');
		fourfour[d].push_back(i);
		file3.getline(e,sizeof(e),'\n');
		num = atol(e);
		fourfre[d].push_back(i);

		temp = fourone.find(a);
		cout << temp->second.back() << " " << temp->first;
		temp = fourtwo.find(b);
		cout << " " << temp->first;
		temp = fourthree.find(c);
		cout << " " << temp->first;
		temp = fourfour.find(d);
		cout << " " << temp->first;
		cout << " " << num << endl;
		i++;
	}
	file3.close();
	cout << endl << endl;


	i = 1;
	while(file4.getline(a,sizeof(a),' ')){//read5
		fiveone[a].push_back(i);
		file4.getline(b,sizeof(b),' ');
		fivetwo[b].push_back(i);
		file4.getline(c,sizeof(c),' ');
		fivethree[c].push_back(i);
		file4.getline(d,sizeof(d),' ');
		fivefour[d].push_back(i);
		file4.getline(e,sizeof(e),'\t');
		fivefive[e].push_back(i);
		file4.getline(f,sizeof(f),'\n');
		num = atol(f);
		fivefre[d].push_back(i);

		temp = fiveone.find(a);
		cout << temp->second.back() << " " << temp->first;
		temp = fivetwo.find(b);
		cout << " " << temp->first;
		temp = fivethree.find(c);
		cout << " " << temp->first;
		temp = fivefour.find(d);
		cout << " " << temp->first;
		temp = fivefive.find(e);
		cout << " " << temp->first;
		cout << " " << num << endl;
		i++;
	}



	char string[const];
	while (cin << string[] != EOF){
		i = 0;
		
		while (string[i] != '\n'){
			if (string[i] == ' ')
				char 
			i++
		}

	}
	
	return 0;
}
