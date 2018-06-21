#include<iostream>
#include<ctime>
#include<cstdio>
#include<unordered_map>
using namespace std;
/*struct data{
	char word = '0';
	double frequency;
	struct data *next[27];
	};
Data *init_tries_root(void);
void build_tries(fstream file, Data *root);*/
int main(int argc,char *argv[])
{
	clock_t start, end;
	start = clock();
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	FILE *twogram, *threegram, *fourgram, *fivegram;
	fivegram = fopen("5gm.small.txt", "r");
	twogram = fopen("2gm.small.txt", "r");
	threegram = fopen("3gm.small.txt", "r");
	fourgram = fopen("4gm.small.txt", "r");
//start here
    unordered_map<string, unsigned long long>M;
	char buff[208];
	unsigned long long temp;
	while(~fscanf(twogram, "%s%llu", buff, &temp))M.insert (make_pair<string,double>(buff, temp));
	while(~fscanf(threegram, "%s%llu", buff, &temp))M.insert (make_pair<string,double>(buff, temp));
	while(~fscanf(fourgram, "%s%llu", buff, &temp))M.insert (make_pair<string,double>(buff, temp));
	while(~fscanf(fivegram, "%s%llu", buff, &temp))M.insert (make_pair<string,double>(buff, temp));
	for(unordered_map<string, unsigned long long>::iterator it = M.begin(); it != M.end(); ++it)
		//cout << it->first << " " << it->second << "\n";*/
	
	fclose(twogram);
	fclose(threegram);
	fclose(fourgram);
	fclose(fivegram);
	end = clock();
	cout << (float)(end - start) / CLOCKS_PER_SEC;
	return 0;
	}	
/*Data *init_tries_root(void){
	return new *Data;
	}
void build_tries(fstream file, Data *root, Data *curr){
	char ch;
	while(file.get(ch)){
		if(ch != ' '){
			curr->next[ch - 'a']->word = ch;
			build_tries(file, root, curr);
			}
		if
		}
	}
*/
