#include<iostream>
using namespace std;
struct TrieNode
{
	TrieNode* next[26];
	int tag;
	string word;
};
int main(void)
{
	
	return 0;
}
void add(char* s)
{
	TrieNode* p = root;
    for (; *s; ++s)
    {
        if (!p->a[*s]) p->a[*s] = new TrieNode();
        p = p->a[*s];
    }
    p->n++;
}
bool lookup(char* s)
{
    TrieNode* p = root;
    for (; *s; ++s)
    {
        if (!p->a[*s]) return false;
        p = p->a[*s];
    }
    return p->n > 0;
}
