#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

void bubble(int ch){							//best case input-Ascending   c(n)=O(n)  	linear
	int i,j,k,count,*arr,flag;					//worst case input-Descending c(n)=O(n^2) 	quad
	FILE *fp1,*fp2;								//Avg case input-random	      c(n)=O(n^2)	quad
	srand(time(NULL));
	
	if(ch==1){
		fp1=fopen("best_input.txt","a");
		fp2=fopen("best_data.txt","a");
	}
	else if(ch==2){
		fp1=fopen("worst_input.txt","a");
		fp2=fopen("worst_data.txt","a");
	}
	else{
		fp1=fopen("Average_input.txt","a");
		fp2=fopen("Average_data.txt","a");
	}
	
	for(i=x;i<y;i+=incre){
		int temp=i;
		arr=(int *)malloc(sizeof(int)*i);
		if(ch==1){
			for(j=0;j<i;j++){
			arr[j]=j+1;
			fprintf(fp1,"%d\t",arr[j]);
		}
		}
		else if(ch==2){
			for(j=0;j<i;j++){
			arr[j]=temp--;
			fprintf(fp1,"%d\t",arr[j]);
			}
		}
		else{
			for(j=0;j<i;j++){
			arr[j]=rand()%100;
			fprintf(fp1,"%d\t",arr[j]);
		}
		}
		fprintf(fp1,"\n");
		
		count=0;
		for(j=0;j<(i-2);j++){
			flag=0;							// remember flag
		for(k=0;k<(i-j-2);k++){
			count++;
			if(arr[k+1]<arr[k]){
				int t=arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=t;
				flag=1;
			}
		}
		if(flag==0){
			break;
		}
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
		case 3:bubble(ch);break;
		}
	}
}
