#include<stdio.h>
#define MAX 20
	
int n,adj[MAX][MAX];
int front = 0,rear = -1,Q[MAX];

void insert_queue(int item){
	if(rear==MAX-1)
		 	 printf("Queue is Full\n");
	Q[++rear]=item;
}


int delete_queue(){
	if(front>rear)
		 	 printf("Queue is Empty\n");
	return Q[front++];
}

int indegree(int z) {
 	 	 int i,incre = 0;
 	 	 for (i = 0;i < n;i++)
 	 		 if(adj[i][z] == 1)
 	 	 		incre++;
 	 	 return incre;
}

void create_graph() {
	 int i,me,o,d,j;
	 printf("\n Enter number of vertices:");
	 scanf("%d",&n);
	 me = n * (n - 1);
	 for (i = 0;i < me;i++) 
	 	 	 for (j = 0;j<me;j++)
	 	 	 	 adj[i][j]=0;
	
	 for (i = 0;i < me;i++) 
	 {
	 	 	 printf("\n Enter edge %d (-1-1 to quit):",i);
	 	 	 scanf("%d%d",&o,&d);
	 	 	 if(o ==-1 && d ==-1)
	 	 	 	 break;
	 	 	 adj[o][d] = 1;
	 }
	 return;
}


void main() {
	 int i,j,k,x=0;
	 int topsort[MAX],indeg[MAX];
	 create_graph();
	 
	 printf("The adjacency matrix is:\n");
	 for(i=0;i<n;i++){
	 	for(j=0;j<n;j++){
			 printf("%d\t",adj[i][j]);
	 	}
	 	printf("\n");
	 }
	 
	 for (i=0;i<n;i++) 
	 {
	 	 	 indeg[i]=indegree(i);
	 	 	 if(indeg[i]==0)
	 	 	 	insert_queue(i);
	 	 	if(indeg[i]>0) 
			    x++;
	 }
	 if(x==n){
			printf("it is cyclic \n");
			return ;
	 }
	 
	 j=0;
	 while(front<=rear) 
	 {
	 	 	 k=delete_queue();
	 	 	 topsort[j++]=k;
	 	 	 for (i=0;i<n;i++) 
	 	 	 {
	 	 	 	 if(adj[k][i]==1) 
	 	 	 	 {
	 	 	 	 	 adj[k][i]=0;
	 	 	 	 	 indeg[i]=indeg[i]-1;
	 	 	 	 	 if(indeg[i]==0)
	 	 	 	 	 insert_queue(i);
	 	 	 	 }
	 	 	 }
	 }
	 
	 if(j == n){
	 		printf("Nodes after topological sorting are:\n");
	 	 	 for (i=0;i<j;i++)
	 	 	 printf("%d",topsort[i]);
	 	 	 printf("\n");
			}
	 else
	 	printf("Solution not available\n");
}

