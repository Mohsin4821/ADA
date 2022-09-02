#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10											//BO:comparision
#define y 100											//best base : constant
#define incre 10										//worst case :log n
												 		//Average case :log n
int support(int arr[],int low,int high,int key){
	int count=0;
	int binary(int arr[],int low,int high,int key){
			if(low < high){
		
				int mid=(high+low)/2;
				
				count++;
				if(arr[mid]==key)
					return count;
				else if(arr[mid]<key)
					binary(arr,mid+1,high,key);
				else
					binary(arr,low,mid-1,key);
			}
		return count;
	}
	return binary(arr,low,high,key);
}

void analysis(int ch){
	int i,j,*arr,key;
	FILE *fp1,*fp2;
	
	fp1=fopen("inpu.txt","a");
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
		
		srand(time(NULL));
		arr=(int *)malloc(i*sizeof(int));
			for(j=0;j<i;j++){
				arr[j]=j;
				fprintf(fp1,"%d\t",arr[j]);
			}
			fprintf(fp1,"\n");
		if(ch==1){
			key=arr[(i-1)/2];
		}
		else if(ch==2){
			key=arr[0];
		}
		else{
			key=arr[rand()%i];
		}
		
		int count=0;
		count=support(arr,0,i-1,key);
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
