#include<stdio.h>
#include<stdlib.h>

int m[10][10],n,conn=0,count=0,cnt=0;

void dfs(int i,int arr[]){

	int j;
	count=count+1;
	arr[i]=count;
	
	for(j=1;j<=n;j++){
		cnt++;
		if(arr[j]==0 && m[i][j]==1){
			printf("->%d",j);
			dfs(j,arr);
		}
	}
}

void DFS(int arr[]){
	int i;
	for(i=1;i<=n;i++){
		if(arr[i]==0){
			printf("%d",i);
			dfs(i,arr);
			conn++;
			printf("\n");
		}
	}
}

void creategraph(){
	int i,s,d,size;
	size=n*(n-1);
	printf("Enter the edges\n-1 -1 to stop\n");
	for(i=1;i<=size;i++){
		printf("Enter edge %d: ",i);
		scanf("%d %d",&s,&d);
		if(s==-1&&d==-1)break;
		m[s][d]=1;
		m[d][s]=1;
	}
}

void main(){
	int i,j,*arr;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			m[i][j]=0;
		}
	}
	creategraph();
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	arr=(int *)malloc(sizeof(int)*n);
	for(i=1;i<=n;i++){
		arr[i]=0;
	}
	DFS(arr);
	printf(" count is %d ",cnt);
	if(conn>1)
		printf("Not connected\n");
	else
		printf("Connected\n");
}

