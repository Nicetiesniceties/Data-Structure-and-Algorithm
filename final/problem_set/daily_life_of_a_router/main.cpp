#include<iostream>
#include<cstdlib>
using namespace std;
struct trie_node{
	struct trie_node *next[2];
	int lease_time;
	int current_time;
};
typedef struct trie_node Node;

Node* NewNode(void);
void add(int *bitsk, Node *root, int time);
int ScanMask(int *bits);
void ScanIP(int *bits);
void lookup(int* bits, Node* root);

int main()
{
	int action;
	scanf("%d", &action);
	Node *root = NewNode();
	while(action--){		
		int command;
		scanf("%d", &command);
		if(command == 1)
		{			
			int bits[33];
			int time = ScanMask(bits);
			add(bits, root, time);
		}
		while(command == 2){
			int bits[33];
			ScanIP(bits);
			lookup(bits, root);
		}
	}
	return 0;
}

Node * NewNode(void){
	Node *New = (Node *)malloc(sizeof(Node));
	New->next[0] = New->next[1] = NULL;
	New->lease_time = 0;
	New->current_time = 0;
	return New;
}
void add(int *bits, Node *root, int time){
	for (int i = 0; bits[i] == 0 || bits[i] == 1; i++){
		if (!root->next[bits[i]]) root->next[bits[i]] = NewNode();
		root = root->next[bits[i]];
    }
	root->lease_time = time;
}
int ScanMask(int *bits){
	int num[4], range, count = 0; char chr;
	for(int i = 0 ; i < 4; i++)scanf("%d%c", &num[i], &chr);
	scanf("%d", &range);
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 8; j++){
			bits[count++] = (num[i] >> 7) & 1;
			num[i] <<= 1; 
			}
	bits[range] = 3;
	int time; 
	scanf("%d", &time);
	return time;
}
void ScanIP(int *bits){
	int num[4], range, count = 0; char chr;
	for(int i = 0 ; i < 3; i++)scanf("%d%c", &num[i], &chr);
	scanf("%d", &num[3]);
	for(int i = 0; i < 4; i++)for(int j = 0; j < 8; j++){
		bits[count++] = (num[i] >> 7) & 1;
		num[i] <<= 1;
	}
}
void lookup(int *bits, Node* root){
	for (int i = 0; i < 32; i++){
        if((root->lease_time) && !(root->current_time)){printf("TRUE\n"); return;}
		if(!root->next[bits[i]]){printf("FALSE\n"); return;}
        root = root->next[bits[i]];
    }
    printf("TRUE\n");
}
