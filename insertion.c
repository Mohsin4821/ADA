#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100
#define incre 10

void insert(int ch){							///same as bubble
	int i,j,k,*arr,count;
	FILE *fp1,*fp2;
	
	if(ch==1){
		fp1=fopen("best.txt","a");
		fp2=fopen("binputdata.txt","a");
		}
	else{
		fp1=fopen("worst.txt","a");
		fp2=fopen("winputdata.txt","a");
	}
	
	for(i=x;i<=y;i+=incre){
		int temp2=i;
		arr=(int *)malloc(sizeof(int)*i);
		if(ch==1){
			for(j=0;j<i;j++){
				arr[j]=j+1;
			}
		}
		else{
			for(j=0;j<i;j++){
				arr[j]=temp2--;
			}
		}
		for(j=0;j<i;j++)
			fprintf(fp1,"%d\t",arr[j]);
		fprintf(fp1,"\n");
		
		count=0;
		for(j=1;j<i;j++){
			int temp=arr[j];
			for(k=j-1;k>=0;k--){
				count++;
				if(arr[k]>temp)
					arr[k+1]=arr[k];
				else
					break;
			}
			arr[k+1]=temp;
		}
		fprintf(fp2,"%d\t%d\n",i,count);
	}
	fclose(fp1);
		fclose(fp2);
}

void main(){
	int ch;
	while(1==1){
	printf("Enter your choice\n");
	printf("1.Best\n2.Worst\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
		case 2:insert(ch);break;
	}
	}
}
