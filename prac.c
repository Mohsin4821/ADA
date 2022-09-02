#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n,adj[20][20],f=0,r=-1,q[20];

void insert(int item){
	if(r==19){
		printf("Queue is full\n");
	}
	q[++r]=item;
}

int delete(){
	if(f>r){
		printf("empty\n");
		exit(0);
	}
	return q[f++];
}

int indegree(int z){
	int i,incre=0;
	for(i=0;i<n;i++){
		if(adj[i][z]==1){
			incre++;
		}
	}
	return incre;
}

void generate(int e){
	int i,s,d;
	for(i=0;i<e;i++){
		printf("Enter edge %d:",i+1);
		scanf("%d %d",&s,&d);
		adj[s][d]=1;
	}
}

void main(){
	int e,i,j,k;
	int topsort[20],indeg[20],x=0;
	
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	
	printf("Enter the number of edges:");
	scanf("%d",&e);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			adj[i][j]=0;
		}
	}
	
	generate(e);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++){
		indeg[i]=indegree(i);
		if(indeg[i]==0)
			insert(i);
		if(indeg[i]>0)
			x++;
	}
	if(x==n){
		printf("Cyclic\n");
		return;
	}
	
	j=0;
	while(f<=r){
		k=delete();
		topsort[j++]=k;
		for(i=0;i<n;i++){
			if(adj[k][i]==1){
				adj[k][i]=0;
				indeg[i]-=1;
				if(indeg[i]==0)
					insert(i);
			}
		}
	}
	
	if(j==n){
		printf("Afetr sorting\n");
		for(i=0;i<n;i++){
			printf("%d",topsort[i]);
		}
	}
	else{
		printf("No solution");
	}
}
