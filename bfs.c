#include<stdio.h>
#include<stdlib.h>

int m[10][10],n,conn=0,count=0,cnt=0;;
int q[10],f=0,r=-1;// 

void bfs(int i,int arr[]){
	int j;
	count=count+1;
	arr[i]=count;
	q[++r]=i;//
	
	while(f<=r){
	
		int x=q[f];
		printf("\n%d",q[f++]);
		for(j=1;j<=n;j++){
			cnt++;
			if(arr[j]==0 && m[x][j]==1){
				count=count+1;
				arr[j]=count;
				q[++r]=j;
			}
		}
	}
}

void BFS(int arr[]){
	int i;
	for(i=1;i<=n;i++){
		if(arr[i]==0){
			printf("%d",i);
			bfs(i,arr);
			conn++;
			printf("\n");
		}
	}
}

creategraph(){
	int i,me,o,d;
	me=n*(n-1);
	for(i=1;i<=me;i++){
		printf("Enter the edge %d or -1 -1to quit: ",i);
		scanf("%d %d",&o,&d);
		if(o==-1&&d==-1)break;
		m[o][d]=1;
		m[d][o]=1;
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
	BFS(arr);
	if(conn>1)
		printf("Not connected\n");
	else
		printf("Connected\n");
	
	printf("%d",cnt);
}
