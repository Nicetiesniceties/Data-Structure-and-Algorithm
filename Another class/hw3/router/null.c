#include<stdio.h>
#include<stdlib.h>
struct trie_node{
    struct trie_node *next[2];
    int tag;
};
typedef struct trie_node Node;
 
Node* NewNode(void);
void add(int *bits, Node *root);
void ScanMask(int *bits);
void ScanIP(int *bits);
void lookup(int* bits, Node* root);
 
int main()
{
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){        
        int M, N;
        scanf("%d%d", &M, &N);
        Node *root = NewNode();
        while(M--){            
            Node *temproot = root;
            int bits[33];
            ScanMask(bits);
            add(bits, temproot);
        }
        while(N--){
            Node *temproot = root;
            int bits[32];
            ScanIP(bits);
            lookup(bits, temproot);
        }
    }
    return 0;
}
 
Node * NewNode(void){
    Node *new = (Node *)malloc(sizeof(Node));
    new->next[0] = new->next[1] = NULL;
    new->tag = 0;
    return new;
}
void add(int *bits, Node *root){
    Node *pre = NewNode();
    for (; *bits == 1 || *bits == 0; ++bits){
        if (!root->next[*bits]) root->next[*bits] = NewNode();
        pre = root;
        root = root->next[*bits];
    }
    pre->tag = 1;
}
void ScanMask(int *bits){
    int num[4], range, count = 0;char chr;
    for(int i = 0 ; i < 4; i++)scanf("%d%c", &num[i], &chr);
    scanf("%d", &range);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 8; j++){
            bits[count++] = (num[i] >> 7) & 1;
            num[i] <<= 1; 
            if(count > range){bits[count] = 3; return;}
        }
}
void ScanIP(int *bits){
    int num[4], range, count = 0;char chr;
    for(int i = 0 ; i < 3; i++)scanf("%d%c", &num[i], &chr);
    scanf("%d", &num[3]);
    for(int i = 0; i < 4; i++)for(int j = 0; j < 8; j++){
        bits[count++] = (num[i] >> 7) & 1;
        num[i] <<= 1;
    }
}
void lookup(int* bits, Node* root){
    for (; *bits == 1 || *bits == 0; ++bits){
        if(root->tag){printf("TRUE\n"); return;}
        if (!root->next[*bits]){printf("FALSE\n"); return;}
        root = root->next[*bits];
    }
	printf("TRUE\n");
}
