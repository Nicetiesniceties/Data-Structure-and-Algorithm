#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
void preorder(Node *root){
	if(root->tag == 3)printf("\n");
	if(root->next[0]){
		printf("0");
		preorder(root->next[0]);
	}
	if(root->next[1]){
		printf("1");
		preorder(root->next[1]);
	}
}
int main(void){
	int bits[33];
	ScanMask(bits);
	for(int i = 0; i < 32; i++){
		//printf("[%d] = %d\n", i, bits[i]);
	}
	Node *root = NewNode();
	add(bits, root);
	preorder(root);
	int BITS[32];
	ScanIP(BITS);
	for(int i = 0; i < 32; i++){
		printf("[%d] = %d\n", i, BITS[i]);
	}
	lookup(BITS, root);
	return 0;
}
