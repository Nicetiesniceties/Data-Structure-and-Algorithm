#include<stdio.h>
#include<stdlib.h>
int Q[500000];//queue
int Qtail=1;
int Qhead=0;
int Qlength=499999;
int index=1;
int n;
typedef struct node
{
 int front;
 int back;
 int port;
 struct node *pi;
 //struct node *next;
 int visit;
}node;
node *city[200010];
node *cityback[200010];
node space[2000000];
node *create_port(node *thiscity,int i){
 thiscity=&space[index];
 thiscity->port=i;
 thiscity->pi=NULL;
 index++;
 return thiscity;
}

node *current;
node *connectfront(node *thiscity,int b){
 current=&space[index];
 current->port=b;
 current->pi=thiscity;
 thiscity=current;
 index++;
 return thiscity;
}
node *connectback(node *thiscity,int a){
 current=&space[index];
 current->port=a;
 current->pi=thiscity;
 thiscity=current;
 index++;
 return thiscity;
}

void enqueue(int Q[],int x){
 Q[Qtail]=x;
 if (Qtail==Qlength)
  Qtail=1;
 else
  Qtail++;  
}

int dequeue(int Q[]){
 int x=Q[Qhead];
 if(Qhead==Qlength)
  Qhead=1;
 else
  Qhead++; 
 return x;
}

void BFSfront(int n,node *source){
 int i,y;
 node *temp;
 for(i=1;i<=n;i++){
  city[i]->front=n;
  city[i]->visit=0;
 }
 }
void BFSback(int n,node *source){
 int i,y;
 node *temp;
 for(i=1;i<=n;i++){
  cityback[i]->back=n;
  cityback[i]->visit=0;
 }
 source->back=0;
 source->visit=1;
 enqueue(Q,n);//source->port==
 while(Qtail!=Qhead){
  y=dequeue(Q);
  temp=cityback[y];//temp=city[]
  while(temp!=NULL){
  if(cityback[temp->port]->visit==0){
   enqueue(Q,temp->port);//Q[  2 5    ]
   cityback[temp->port]->back=cityback[y]->back+1; //city[]->front==1
   cityback[temp->port]->visit=1;// city[3],[2] visited
  }
  temp=temp->pi;
  }
 }
}
int main(){
 
 int T,m,q;
 int h,i,j,k;
 int a,b;
 int dis;
 
 scanf("%d",&T);
 
 for(h=0;h<T;h++){
  
  scanf("%d%d%d",&n,&m,&q); 
  
  for(i=1;i<=n;i++){
   city[i]=create_port(city[i],i);//city[1]~city[8]
   cityback[i]=create_port(cityback[i],i);
  }
  
  for(j=0;j<m;j++){
   scanf("%d%d",&a,&b);
   city[a]=connectfront(city[a],b);
   cityback[b]=connectback(cityback[b],a);
  }
  
  BFSfront(n,city[1]);
  Qtail=1;
  Qhead=0;
  BFSback(n,cityback[n]);
  city[1]->front=0;
  cityback[n]->back=0;
  for(k=0;k<q;k++){
   scanf("%d%d",&a,&b);
   dis = city[a]->front + 1 + city[n]->front - city[b]->front;

   if(dis < city[n]->front)
    printf("%d\n",dis);
   else{
    printf("%d\n",city[n]->front);
    //printf("dis is %d.\n",dis);
    //printf("city[a]->front is %d\ncity[n]->front is %d\ncity[b]->front is %d\n",
    //city[a]->front,city[n]->front, city[b]->front);
   }
//for(i=1;i<=n;i++)
   // printf("city[%d]->front=%d.\n",i,city[i]->front);
      
   
  }
  
 }


 return 0;
}
