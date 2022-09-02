#include<stdio.h>
#include<stdlib.h>

int n,a[20][20],b[20][20],count=0;

void create_graph(){
	int i,s,d,size;			//source //destination //size of matrix 
	size=n*(n-1);
	printf("Enter the edges\n-1 -1 to stop\n");
	for(i=1;i<=size;i++){
		printf("Enter edge %d: ",i);
		scanf("%d %d",&s,&d);
		if(s==-1 && d==-1)
		break;
		a[s][d]=1;
	}
}

void warshal(){
	int i,j,k;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
	//		if(a[i][k]==1){
			for(j=1;j<=n;j++){
			count++;
		//	if(a[i][j]==1||a[k][j]==1)
					b[i][j]=(a[i][j]||(a[i][k]&&a[k][j]));
		//			b[i][j]=1;
			a[i][j]=b[i][j];
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
			a[i][j]=0;
			b[i][j]=0;
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
	
	warshal();
	printf("Transitive closure\n");
	for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%d\t",b[i][j]);			
		}
		printf("\n");
	}
	printf("count:%d",count);
}
