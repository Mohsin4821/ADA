#include<stdio.h>
#include<stdlib.h>

int m[10][10],n,var=0,count=0,cnt=0;
int stack[10],top=-1;

void dfs(int i,int arr[]){
	int j;
	count+=1;
	arr[i]=count;
	
	for(j=1;j<n;j++){
		count+=1;
		if(arr[j]==0 && m[i][j]==1){
			printf("->%d",j);
			dfs(j,arr);
			stack[++top]=j;
			var++;
		}
	}
}	

void DFS(int arr[]){
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==0){
			printf("%d",i);
			dfs(i,arr);
			stack[++top]=i;
			var++;
			printf("\n");
		}
	}
}

void generate(int e){
	int i,j,k;
	for(k=1;k<=e;k++){
		printf("Enter the connection %d: ",k);
		scanf("%d %d",&i,&j);
		m[i][j]=1;
	}
}

void main(){
	int i,j,e,*arr;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	printf("Enter number of edges\n");
	scanf("%d",&e);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				m[i][j]=0;
		}
	}
	
	generate(e);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	
	arr=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		arr[i]=0;
	}
	DFS(arr);
	for(j=var-1;j>=0;j--){
		printf("%d",stack[j]);
	}
	printf("\ncount=%d",count);
}
