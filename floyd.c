#include<stdio.h>
#include<stdlib.h>

int n,a[20][20],count=0;

void create_graph(){
	int i,j,s,d,size,dis;		//source //destination //size of matrix //distances
	size=n*(n-1);
	printf("Enter the edges\n-1 -1 to stop\n");
	for(i=1;i<=size;i++){
		printf("Enter edge %d: ",i);
		scanf("%d %d",&s,&d);
		if(s==-1 && d==-1)
			break;
		printf("Enter the distance\n");
		scanf("%d",&dis);
		a[s][d]=dis;
	}
}

int min(int a,int b){
	if(a>b)return b;
	return a;
}

void floyd(){
	int i,j,k;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				count++;
				if(i!=j)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
}

void main(){
	int i,j;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)
			a[i][j]=0;
			else
			a[i][j]=999;
		}
	}
	
	create_graph();
	
	printf("Adjacency matrix\n");
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%d\t",a[i][j]);			
		}
		printf("\n");
	}
	
	floyd();
	printf("Distance matrix\n");
	for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%d\t",a[i][j]);			
		}
		printf("\n");
	}
	printf("count:%d",count);
}

