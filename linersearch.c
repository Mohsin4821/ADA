#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10						//Basic operation : comparison

void analysis(int ch){					//best case  c(n)=O(1)   		constant
	int i,j,*arr,count,key;				//worst case c(n)=O(n)	 		linear	
	FILE *fp1,*fp2;						//avg case   c(n)=O((n+1)/2)	linear
										
	srand(time(NULL));
	fp1=fopen("input.txt","a");
	if(ch==1){
		fp2=fopen("Best_data.txt","a");
	}
	else if(ch==2){
		fp2=fopen("Worst_data.txt","a");
	}
	else{
		fp2=fopen("Average_data.txt","a");
	}
	
	for(i=x;i<=y;i+=incre){
		arr=(int *)malloc(sizeof(int)*i);
			for(j=0;j<i;j++){
				arr[j]=j;
				fprintf(fp1,"%d\t",arr[j]);
			}
			fprintf(fp1,"\n");
			
		if(ch==1){
			key=arr[0];
		}
		else if(ch==2){
			key=arr[i-1];
		}
		else{
			key=arr[i/2];
		}
		
		count=0;
		for(j=0;j<i;j++){
			count++;
			if(arr[j]==key) break;
		}
		
		fprintf(fp2,"%d\t%d\n",i,count);
	}
		fclose(fp1);
		fclose(fp2);
}

void main(){
	int ch;
	while(1){
		printf("Enter your choice\n1.Best\n2.Worst\n3.Average\n");
		scanf("%d",&ch);
		switch(ch){
		case 1:
		case 2:
		case 3:analysis(ch);break;
		}
	}
}
