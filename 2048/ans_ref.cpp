#include<cstdlib>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<vector>
#include<stdio.h>
using namespace std;
int a, i, j, c[6][6], t, goal, z;
vector<int> allsteps;
unsigned long long nextMap(unsigned long long map, int action);
unsigned long long cur2, fin;
unsigned long long check2048(unsigned long long cur){
    for(j=0; j<16; j++, cur=cur>>4){
        a=cur%16;
        if(a==11){
            return 1;
        }
    }
    return 0;
}
unsigned long long dfs(unsigned long long cur, int action){
    if(cur==nextMap(cur, action)){
        return 0;
    }
    cur=nextMap(cur, action);
    goal=check2048(cur);
    if(goal==1){
        allsteps.push_back(action);
        fin=cur;
        return 0;
    }
    allsteps.push_back(action);
    if(goal==0){
        dfs(cur, 0);}
    if(goal==0){
        dfs(cur, 1);}
    if(goal==0){
        dfs(cur, 2);}
    if(goal==0){
        dfs(cur, 3);}
    if(goal==0){
        allsteps.pop_back();}
return 0;
}
 
int main(){
int n, b[16], action;
unsigned long long m;
cin>>n;
for(z=0; z<n; z++){
    for(j=0; j<16; j++){
        cin>>a;
        if(a==0){
            b[j]=0;
        }
        else{
            b[j]=log2(a);
        }
    }
    m=0;
    for(j=15; j>0; j--){
        m+=b[j];
        m=m<<4;
    }
    m+=b[0];
    goal=0;
    for(j=0; j<4; j++){
        dfs(m, j);
        if(goal==1){
            break;
        }
    }
    if(goal==1){
        printf("Action:\n");
        for(j=0; j<allsteps.size()-1; j++){
            printf("%d ", allsteps[j]);
        }
        printf("%d\n", allsteps[j]);
        printf("Final:\n");
        for(j=0; j<16; j++, fin=fin>>4){
            a=fin%16;
            if(a==0){
                printf("0");
            }
            else{ 
                t=pow(2, a);
                printf("%d", t);
            }
            if(j%4==3){
                printf("\n");
            }
            else{
            printf(" ");
            }
        }
    }
    else{
        printf("Action:\n");
        printf("-1\n");
        printf("Final:\n");
        for(j=0; j<16; j++){
            printf("-1");
            if(j%4==3){
                printf("\n");
            }
            else{
            printf(" ");
            }
        }
    }
    allsteps.clear();
}
 
}
